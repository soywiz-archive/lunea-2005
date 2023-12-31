/*  $Id: call_stack.h,v 1.4 2004/02/01 03:07:16 mbn Exp $
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

//! clanCore="System"
//! header=core.h

#ifndef header_call_stack
#define header_call_stack

#if _MSC_VER > 1000
#pragma once
#endif

#include "sharedptr.h"

class CL_CallStack_Generic;

//: Call stack for stack back trace.
//- !group=Core/System!
//- !header=core.h!
class CL_CallStack
{
//! Construction:
public:
	CL_CallStack();

	~CL_CallStack();

//! Attributes:
public:
	//: Returns the number of stack call frames available.
	int get_num_frames() const;

	//: Returns the specified stack frame.
	const std::string &get_call_frame(int frame) const;

//! Operations:
public:
	//: Adds a frame description to the call stack.
	void add_call_frame(const std::string &str_frame);

//! Implementation:
private:
	CL_SharedPtr<CL_CallStack_Generic> impl;
};

#endif
