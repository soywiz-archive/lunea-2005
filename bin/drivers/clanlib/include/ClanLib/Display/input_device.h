/*  $Id: input_device.h,v 1.20 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_inputdevice
#define header_inputdevice

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include <string>

#include "../signals.h"

class CL_InputDevice_Generic;
class CL_InputEvent;

//: General input device.
//- !group=Display/Input!
//- !header=display.h!
class CL_InputDevice
{
public:
	//: Input device types.
	enum Type
	{
		keyboard,
		mouse,
		joystick
	};

//! Construction:
public:
	//: Constructs an input device.
	CL_InputDevice();

	CL_InputDevice(const CL_InputDevice &copy);

	~CL_InputDevice();

//! Attributes:
public:
	//: Returns the name of the device (i.e. 'Microsoft Sidewinder 3D').
	std::string get_name() const;

	//: Returns the input device type.
	Type get_type() const;

	//: Friendly key name for specified identifier (A, B, Space, Backspace, Mouse Left).
	//- <p>Note that this key name is localized, meaning it should only be used for menus
	//- where the user view key bindings, and not configuration files and such.</p>
	std::string get_key_name(int id) const;

	//: Returns a generic string name for the specified key code. 
	std::string keyid_to_string(int keycode) const;

	//: Returns the key code for the specified generic string key name.
	int keyid_to_string(const std::string &str) const;

	//: Returns true if the passed key code is down for this device.
	//- <p>See keys.h for list of key codes.</p>
	bool get_keycode(int keycode) const;
	
	//: Returns the x position of the device.
	//- <p>Only valid for mouse.</p>
	int get_x() const;

	//: Returns the y position of the device.
	//- <p>Only valid for mouse.</p>
	int get_y() const;

	//: Returns the the current position of a joystick axis.
	float get_axis(int index) const;

	//: Returns the number of axes available on this device.
	int get_axis_count() const;

	//: Returns the number of buttons available on this device.
	//- <p>If used on a keyboard, this function returns -1.</p>
	int get_button_count() const;

//! Operations:
public:
	CL_InputDevice &operator =(const CL_InputDevice &copy);

	//: Sets the position of the device.
	//- <p>Only valid for mouse.</p>
	void set_position(int x, int y);

//! Signals:
public:
	//: Signal emitted when key is pressed.
	CL_Signal_v1<const CL_InputEvent &> &sig_key_down();

	//: Signal emitted when key is released.
	CL_Signal_v1<const CL_InputEvent &> &sig_key_up();

	//: Signal emitted when key is double clicked.
	CL_Signal_v1<const CL_InputEvent &> &sig_key_dblclk();

	//: Signal emitted when pointer is moved (absolute movement).
	CL_Signal_v1<const CL_InputEvent &> &sig_pointer_move();

	//: Signal emitted when pointer's ball is moved (relative movement).
	CL_Signal_v1<const CL_InputEvent &> &sig_ball_move();

	//: Signal emitted when axis is moved.
	CL_Signal_v1<const CL_InputEvent &> &sig_axis_move();

	//: Deprecated. Use sig_pointer_move() instead.
	CL_Signal_v1<const CL_InputEvent &> &sig_move();

//! Implementation:
public:
	CL_InputDevice(CL_InputDevice_Generic *impl);

private:
	CL_InputDevice_Generic *impl;
};

#endif
