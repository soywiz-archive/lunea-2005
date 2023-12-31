/*  $Id: input_context.h,v 1.18 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_input_context
#define header_input_context

#if _MSC_VER > 1000
#pragma once
#endif

#include "../signals.h"

class CL_InputDevice;
class CL_InputEvent;
class CL_InputContext_Generic;

//: Input events interface.
//- !group=Display/Input!
//- !header=display.h!
//- <p>An input context is a collection of inputdevices available in
//- a displaywindow.</p>
class CL_InputContext
{
//! Construction:
public:
	//: Constructs an input context.
	CL_InputContext();

	CL_InputContext(const CL_InputContext &copy);

	~CL_InputContext();

//! Attributes:
public:
	//: Returns the number of keyboards available.
	int get_keyboard_count() const;

	//: Returns the number of mice available.
	int get_mouse_count() const;

	//: Returns the number of joysticks available.
	int get_joystick_count() const;

	//: Returns the input device for the specified keyboard.
	CL_InputDevice &get_keyboard(int keyboard = 0);

	//: Returns the input device for the specified mouse.
	CL_InputDevice &get_mouse(int mouse = 0);

	//: Returns the input device for the specified joystick.
	CL_InputDevice &get_joystick(int joystick = 0);

//! Operations:
public:
	//: Copy assignment operator.
	CL_InputContext &operator =(CL_InputContext &copy);

	//: Removes all devices from this input context.
	void clear();

	//: Adds a new keyboard to the input context.
	void add_keyboard(const CL_InputDevice &keyboard);

	//: Adds a new mouse to the input context.
	void add_mouse(const CL_InputDevice &mouse);

	//: Adds a new joystick to the input context.
	void add_joystick(const CL_InputDevice &joystick);

//! Implementation:
private:
	CL_InputContext_Generic *impl;
};

#endif
