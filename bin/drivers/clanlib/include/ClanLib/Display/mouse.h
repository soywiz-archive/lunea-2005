/*  $Id: mouse.h,v 1.6 2004/01/02 15:42:43 mbn Exp $
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

//! clanDisplay="Input"
//! header=display.h

#ifndef header_mouse
#define header_mouse

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include <string>
#include "../signals.h"

class CL_InputEvent;
class CL_InputDevice;
class CL_Sprite;

//: Class for handling mouse device.
//- !group=Display/Input!
//- !header=display.h!
class CL_Mouse
{
//! Construction:
public:

//! Attributes:
public:
	//: Returns the number of mice available.
	static int get_device_count();

	//: Returns a mouse device.
	static CL_InputDevice &get_device(int mouse = 0);

	//: Returns the x position of a mouse device.
	static int get_x(int mouse = 0);
	
	//: Returns the y position of a mouse device.
	static int get_y(int mouse = 0);
	
	//: Returns true if the key with the specified key code is pressed.
	static bool get_keycode(int keycode, int mouse = 0);

	//: Key name for specified identifier (Mouse Left, Mouse Right).
	static std::string get_key_name(int id);

//! Operations:
public:
	//: Sets the position of a mouse device.
	static void set_position(int x, int y, int mouse = 0);

	//: Set a custom mouse cursor.
	static void set_cursor(const CL_Sprite &sprite);

	//: Shows the mouse cursor. 
	static void show();

	//: Hides the mouse cursor.
	static void hide();

//! Signals:
public:
	//: Signal emitted when mouse is pressed on the specified mouse.
	static CL_Signal_v1<const CL_InputEvent &> &sig_key_down(int mouse = 0);

	//: Signal emitted when mouse is released on the specified mouse.
	static CL_Signal_v1<const CL_InputEvent &> &sig_key_up(int mouse = 0);

	//: Signal emitted when mouse is double clicked.
	static CL_Signal_v1<const CL_InputEvent &> &sig_key_dblclk(int mouse = 0);

	//: Signal emitted when specified mouse is moved.
	static CL_Signal_v1<const CL_InputEvent &> &sig_move(int mouse = 0);

//! Implementation:
private:
};

#endif
