#include <lunea_define.h>
#include <lunea_debug.h>
#pragma once

CL_GraphicContext *cl_window_gc;

class LuneaApp : public CL_ClanApplication {
public:
	virtual int main(int argc, char **argv) {
		mouse_struct mousesc;
		mouse = &mousesc;

		// Create a console window for text-output if not available
		//LUNEA_DEBUG { CL_ConsoleWindow console("Console"); }
		//LUNEA_DEBUG { console.redirect_stdio(); }

		quit = false;

		MAIN_PROCESS_LIST = new LPROCESS_LIST();
		TEMP_PROCESS_LIST = new LPROCESS_LIST();

		new start();

		try {
			CL_SetupCore::init();
			CL_SetupDisplay::init();
			CL_SetupGL::init();
			CL_DisplayWindow window("Lunea Application", 640, 480);

			CL_Slot slot_quit      = window.sig_window_close().connect(this, &LuneaApp::on_window_close);
			CL_Slot slot_input_up  = (window.get_ic()->get_keyboard()).sig_key_up().connect(this, &LuneaApp::on_input_up);

			// SOUND TEST

			CL_SetupMikMod::init();

			CL_SoundOutput sound_output(44100);

			//music_playback = CL_SoundBuffer_Session();

			music_playback_started = false;

			cl_window_gc = window.get_gc();

			//CL_SoundBuffer sample("guitarou.mod");
			//CL_SoundBuffer_Session playback(sample.prepare());

			//playback.play();

			// /SOUND TEST


			//CL_Surface sur_logo("logo.tga");

			//double sin_count = 0.0f;
			//float ypos = 0.0f;
			//float ydir = 3.0f;

			mouse->wheel = 0;
			mouse->left  = false;

			while (!quit) {
				CL_Display::clear(CL_Color(0, 0, 0));

				bool bleft     = mouse->left;

				mouse->x      = CL_Mouse::get_x();
				mouse->y      = CL_Mouse::get_y();
				mouse->left   = CL_Mouse::get_keycode(CL_MOUSE_LEFT);
				mouse->middle = CL_Mouse::get_keycode(CL_MOUSE_MIDDLE);
				mouse->right  = CL_Mouse::get_keycode(CL_MOUSE_RIGHT);
				mouse->xb1    = CL_Mouse::get_keycode(CL_MOUSE_XBUTTON1);
				mouse->xb2    = CL_Mouse::get_keycode(CL_MOUSE_XBUTTON2);
				if (CL_Mouse::get_keycode(CL_MOUSE_WHEEL_UP))   mouse->wheel--;
				if (CL_Mouse::get_keycode(CL_MOUSE_WHEEL_DOWN)) mouse->wheel++;

				mouse->clicked = (!bleft && mouse->left);

				TEMP_PROCESS_LIST->moveTo(MAIN_PROCESS_LIST);
				MAIN_PROCESS_LIST->execute();
				MAIN_PROCESS_LIST->draw();

				CL_Display::flip();
				CL_System::keep_alive(600 / 60);
			}

			CL_SetupGL::deinit();
			CL_SetupDisplay::deinit();
			CL_SetupCore::deinit();
		} catch(CL_Error error) {
			std::cout << "Exception caught : " << error.message.c_str() << std::endl;

			//LUNEA_DEBUG console.display_close_message();

			return -1;
		}

		return 0;
	}
private:
	bool quit;

	void on_input_up(const CL_InputEvent &key) {
		if (key.id == CL_KEY_ESCAPE) quit = true;
	}

	void on_window_close() {
		quit = true;
	}
} my_app;

bool key(int key) {
	return CL_Keyboard::get_keycode(key);
}

mouse_struct *mouse;