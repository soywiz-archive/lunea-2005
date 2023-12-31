	/*  $Id: input_buffer.h,v 1.14 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_inputbuffer
#define header_inputbuffer

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include <queue>
#include "input_event.h"
#include "../signals.h"

class CL_Component;
class CL_InputDevice;
class CL_InputContext;
class CL_InputBuffer_Generic;

//: Input buffer interface.
//- !group=Display/Input!
//- !header=display.h!
//- <p> Use this class to read buffered keys from the keyboard or any other device. </p>
class CL_InputBuffer
{
//! Construction:
public:
	//: Constructs an input buffer.
	//param ic: Input context that input buffer should connect to get keys.
	//param sig_key_down: Signal input buffer should connect to get key presses.
	//param sig_key_up: Signal input buffer should connect to get key released.
	//param device: Input device that input buffer should connect to get keys.
	//- <p>Detailed description that explains what this damn constructors really do.</p>
	CL_InputBuffer();

	CL_InputBuffer(CL_InputDevice &device);

	CL_InputBuffer(CL_InputContext *ic);

	CL_InputBuffer(const CL_InputBuffer &copy);

	//: Input Buffer destructor.
	virtual ~CL_InputBuffer();

//! Attributes:
public:
	//: Returns number of keys still available in the buffer.
	//return: Number of key values left in buffer.
	int keys_left() const;

	//: Returns the next key in the buffer, but unlike pop_key() it does not
	//: pop it from the input buffer.
	CL_InputEvent peek_key() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_InputBuffer &operator =(const CL_InputBuffer &copy);

	//: Adds a device that input buffer should connect to get keys.
	void add_device(CL_InputDevice &device);

	//: Adds all devices from a inputcontext that input buffer should connect to get keys.
	void add_devices(CL_InputContext *ic);
	
	//: Pops the next key in the buffer and returns it.
	CL_InputEvent pop_key();

	//: Clears the buffer.
	void clear();
	
//! Implementation:
private:
	CL_InputBuffer_Generic *impl;
};

#endif
