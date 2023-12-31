	/*  $Id: key_binding.h,v 1.7 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_keybinding
#define header_keybinding

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_KeyBinding_Generic;
class CL_InputDevice;

//: Input Button binding interface.
//- !group=Display/Input!
//- !header=display.h!
//- Use this class to ...
class CL_KeyBinding
{
//! Construction:
public:
	//: Constructor.
	CL_KeyBinding();

	//: Constructor.
	CL_KeyBinding(int keycode, const CL_InputDevice &device);

	//: Copy constructor.
	CL_KeyBinding(const CL_KeyBinding &copy);

//! Attributes:
public:
	//:
	bool operator ==(const CL_KeyBinding &other) const;

	//:
	bool operator <(const CL_KeyBinding &other) const;

	//:
	bool operator >(const CL_KeyBinding &other) const;

	//:
	CL_InputDevice &get_device() const;

	//:	
	int get_keycode() const;

	//:
	std::string get_key_name() const;

//! Operations:
public:
	//:
	CL_KeyBinding &operator =(const CL_KeyBinding &copy);

	//:
	void set_keycode(int keycode);

	//:
	void set_device(const CL_InputDevice &device);

//! Implementation:
private:
	CL_KeyBinding_Generic *impl;
};

#endif
