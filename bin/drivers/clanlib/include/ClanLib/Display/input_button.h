	/*  $Id: input_button.h,v 1.4 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_inputbutton
#define header_inputbutton

#if _MSC_VER > 1000
#pragma once
#endif

#include "input_event.h"
#include "key_binding.h"

class CL_InputButton_Generic;

//: Input Button interface.
//- !group=Display/Input!
//- !header=display.h!
//- Use this class to bind inputevents to this class. You can then check if any input events has
//- be activated (like a mouse-press, a certain keypress etc).
//- Useful for things like mapping SPACE and LEFT MOUSE to a Fire Action.
class CL_InputButton
{
//! Construction:
public:
	//: Constructor.
	CL_InputButton();

	//: Copy constructor.
	CL_InputButton(const CL_InputButton &copy);

	//: Destructor.
	virtual ~CL_InputButton();

//! Attributes:
public:
	//: Returns the number of presses this inputbutton has been pressed.
	//- Returns - Number of key presses of this inputbutton.
	int peek_pressed() const;

	//: Returns the CL_InputEvent of the last input press.
	//- Returns - CL_InputEvent of the last input press.
	CL_InputEvent peek_key() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_InputButton &operator =(const CL_InputButton &copy);

	//: Binds a key.
	void bind(const CL_KeyBinding &key);

	//: Unbinds a key.
	void unbind(const CL_KeyBinding &key);

	//: Unbinds all keys.
	void unbind_all();

	//: Returns a list over all keys bound to this inputbutton.
	const std::list<CL_KeyBinding> &get_bindings() const;

	//: Returns the number of presses this inputbutton has been pressed.
	//: This clears the state of this inputbutton.
	//- Returns - Number of key presses of this inputbutton.
	int pop_pressed();

	//: Returns the CL_InputEvent of the last input press.
	//: This clears the state of the inputbutton.
	//- Returns - CL_InputEvent containing information on last input press.
	CL_InputEvent pop_key();

	//: Clears the state of the inputbutton.
	void clear();

//! Implementation:
private:
	CL_InputButton_Generic *impl;
};

#endif
