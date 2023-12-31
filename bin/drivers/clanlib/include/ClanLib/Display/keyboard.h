/*  $Id: keyboard.h,v 1.14 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_keyboard
#define header_keyboard

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

//: Keyboard class.
//- !group=Display/Input!
//- !header=display.h!
class CL_Keyboard
{
//! Construction:
public:

//! Attributes:
public:
	//: Returns the number of keyboards available.
	static int get_device_count();

	//: Returns a keyboard device.
	static CL_InputDevice &get_device(int keyboard = 0);

	//: Returns true if the key with the specified key code is pressed.
	static bool get_keycode(int keycode, int keyboard = 0);

	//: Key name for specified identifier (A, B, Space, Backspace).
	static std::string get_key_name(int id);

//! Operations:
public:

//! Signals:
public:
	//: Signal emitted when key is pressed on the specified keyboard.
	static CL_Signal_v1<const CL_InputEvent &> &sig_key_down(int keyboard = 0);

	//: Signal emitted when key is released on the specified keyboard.
	static CL_Signal_v1<const CL_InputEvent &> &sig_key_up(int keyboard = 0);

	//: Signal emitted when key is double clicked on the specified keyboard.
	static CL_Signal_v1<const CL_InputEvent &> &sig_key_dblclk(int keyboard = 0);

//! Implementation:
private:
};

#endif
