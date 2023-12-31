/*  $Id: slot.h,v 1.20 2004/01/28 01:17:37 mbn Exp $
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

//! clanSignal="System"
//! header=signals.h

#ifndef header_slot
#define header_slot

#if _MSC_VER > 1000
#pragma once
#endif

class CL_Slot_Generic;

//: Slot class
//- !group=Signal/System!
//- !header=signals.h!
class CL_Slot
{
//! Construction:
public:
	//: Create an unconnected slot.
	CL_Slot();

	//: Copy a slot.
	CL_Slot(const CL_Slot &copy);

	//: Slot destructor
	~CL_Slot();

//! Attributes:
public:
	//: Returns the number of CL_Slot references still pointing at this slot.
	int get_slot_ref() const;

	//: Returns the number of signals this slot is connected to.
	int get_signal_ref() const;

	//: Returns true if slot is persistent.
	//- <p>If the slot is persistent, it will remain connected to
	//- signals even when all references to CL_Slot are gone.</p>
	bool is_persistent() const;

//! Operations:
public:
	//: Slot copy operator
	void operator =(const CL_Slot &copy);

	//: Sets the persistent flag.
	//- <p>If the slot is persistent, it will remain connected to
	//- signals even when all references to CL_Slot are gone.</p>
	void set_persistent(bool flag = true);

//! Implementation:
public:
	//: Slot constructor
	CL_Slot(CL_Slot_Generic *impl);

	//: Slot Generic Implementation
	CL_Slot_Generic *impl;
};

#endif
