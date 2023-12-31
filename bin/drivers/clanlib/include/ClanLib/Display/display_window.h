/*  $Id: display_window.h,v 1.43 2004/03/10 23:16:39 mbn Exp $
**
**  ClanLib Game SDK
**  Copyright (C) 2003  The ClanLib Team
**  For a total list of contributers see the file CREDITS.
**
**  This library is free software; you can redistribute it and/or
**  modify it under the terms of the GNU Lesser General Public
**  License as published by the Free Software Foundation; either
**  version 2.1 of the License, or (at your option) any later version.
**
**  This library is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
**  Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public
**  License along with this library; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
**
*/

//! clanDisplay="Display 2D"
//! header=display.h

#ifndef header_display_window
#define header_display_window

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include <string>
#include "../signals.h"

class CL_PixelBuffer;
class CL_InputEvent;
class CL_Rect;
class CL_Size;
class CL_GraphicContext;
class CL_InputContext;
class CL_DisplayWindow_Generic;
class CL_Sprite;
class CL_DisplayWindowDescription;
class CL_DisplayMode;

//: Toplevel window class.
//- !group=Display/Display 2D!
//- !header=display.h!
//- <p>CL_DisplayWindow represents a window in your windowing system
//- (Windows, X11). You need to create at least one display window in order
//- to draw graphics in ClanLib.</p>
class CL_DisplayWindow
{
//! Construction:
public:
	//: Constructs a window.
	//param title: Titlebar text.
	//param width: Width in pixels of window.
	//param height: Height in pixels of window.
	//param start_fullscreen: If true, window will go fullscreen.
	//param allow_resize: If true, window will have resize grabbers and can be resized.
	//param flipping_buffers: Number of flipping buffers in system.
	//param flipping_buffers: Default is that there is a front buffer and a back buffer.
	//param description: Structure that describes how to create the display window.
	CL_DisplayWindow();

	CL_DisplayWindow(const CL_DisplayWindow &copy);

	CL_DisplayWindow(
		const std::string &title,
		int width,
		int height,
		bool start_fullscreen = false,
		bool allow_resize = false,
		int flipping_buffers = 2);

	CL_DisplayWindow(const CL_DisplayWindowDescription &description);

	~CL_DisplayWindow();

//! Attributes:
public:
	//: Returns the current width of the window.
	int get_width() const;

	//: Returns the current height of the window.
	int get_height() const;

	//: Returns true if window is currently running fullscreen.
	bool is_fullscreen() const;

	//: Returns true if window has focus.
	bool has_focus() const;

	//: Returns the pixel buffer for the specified flipping buffer.
	CL_PixelBuffer &get_buffer(int i);

	const CL_PixelBuffer &get_buffer(int i) const;

	//: Returns the amount of flipping buffers being used.
	int get_buffer_count() const;

	//: Returns the current flipping buffer being used as the front buffer.
	CL_PixelBuffer &get_front_buffer();

	const CL_PixelBuffer &get_front_buffer() const;

	//: Returns the current flipping buffer being used as the back buffer.
	CL_PixelBuffer &get_back_buffer();

	const CL_PixelBuffer &get_back_buffer() const;

	//: Returns the graphic context of the current back buffer.
	CL_GraphicContext *get_gc();

	//: Returns the input context of this window.
	CL_InputContext *get_ic();

//! Operations:
public:
	//: Copy assignment operator.
	CL_DisplayWindow &operator =(const CL_DisplayWindow &copy);

	//: Change window to running fullscreen mode.
	void set_fullscreen(int width=0, int height=0, int bpp=0, int refresh_rate=0);

	//: Change window to running fullscreen mode.
	void set_fullscreen(const CL_DisplayMode &display_mode);

	//: Change window to running windowed mode.
	void set_windowed();

	//: Change window title.
	void set_title(const std::string &title);

	//: Set window position and size.
	//param pos: Window position and size.
	//param x: Window x position on desktop.
	//param y: Window y position on desktop.
	void set_position(const CL_Rect &pos);

	void set_position(int x, int y);

	//: Resize window.
	//param width: New width of window in pixels.
	//param height: New height of window in pixels.
	void set_size(int width, int height);

	//: Changes the amount of pixel buffers used in the flipping system.
	//param flipping_buffers: New number of flipping buffers.
	//- <p>2 = double buffer, 3 = triple buffer.</p>
	void set_buffer_count(int flipping_buffers);

	//: Copy the specified rectangle area from back buffer to front buffer.
	//param rect: Area that should be copied.
	void update(const CL_Rect &rect);

	//: Flip back buffer to front, making changes visible on screen.
	//param interval: Specifies the minimum number of video frames that are displayed before a buffer swap will occur.
	//- <p>The parameter interval specifies the minimum number of video frames
	//- that are displayed before a buffer swap will occur.</p>
	//- <p>A video frame period is the time required by the monitor to display a 
	//- full frame of video data.  In the case of an interlaced monitor,
	//- this is typically the time required to display both the even and odd 
	//- fields of a frame of video data.  An interval set to a value of 2
	//- means that the color buffers will be swapped at most every other video
	//- frame.</p>
	//- <p>If interval is set to a value of 0, buffer swaps are not synchronized
	//- to a video frame.  The interval value is silently clamped to
	//- the maximum implementation-dependent value supported before being
	//- stored.</p>
	//- <p>If interval is set to a value of -1 (the default), then it will use
	//- the buffer swap used for previous flip. If its the first flip, it will
	//- use the system default, which per default is 1.</p>
	void flip(int interval = -1);

	//: Sets the mouse cursor shape.
	void set_cursor(const CL_Sprite &cursor);

	//: Shows the mouse cursor.
	void show_cursor();

	//: Hides the mouse cursor.
	void hide_cursor();

//! Signals:
public:
	//: Signal emitted when window lost focus.
	CL_Signal_v0 &sig_lost_focus();

	//: Signal emitted when window gain focus.
	CL_Signal_v0 &sig_got_focus();

	//: Signal emitted when window is resized.
	CL_Signal_v2<int, int> &sig_resize();

	//: Signal emitted when an area of the window is invalidated.
	CL_Signal_v1<const CL_Rect &> &sig_paint();

	//: Signal emitted when window is closed.
	CL_Signal_v0 &sig_window_close();

//! Implementation:
protected:
	CL_DisplayWindow(CL_DisplayWindow_Generic *impl);

	CL_DisplayWindow_Generic *impl;
};

#endif
