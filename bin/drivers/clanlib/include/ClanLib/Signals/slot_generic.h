/*  $Id: slot_generic.h,v 1.13 2004/01/28 01:17:37 mbn Exp $
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

#ifndef header_slot_generic
#define header_slot_generic

#if _MSC_VER > 1000
#pragma once
#endif

#include <list>
#include "signal.h"

class CL_Slot;

//: Slot Generic Class
//- !group=Signal/System!
//- !header=signals.h!
class CL_Slot_Generic
{
//! Construction:
public:
	//: Slot Generic Constructor
	CL_Slot_Generic();

	//: Slot Generic Destructor
	virtual ~CL_Slot_Generic();

//! Attributes:
public:
	//: Get slot ref
	int get_slot_ref() const;

	//: Get signal ref
	int get_signal_ref() const;

	//: Returns true if persistent.
	//- <p>If the slot is persistent, it will remain connected to
	//- signals even when all references to CL_Slot are gone.</p>
	bool is_persistent() const;

//! Operations:
public:
	//: Add slot ref
	void add_slot_ref();

	//: Release slot ref
	void release_slot_ref();

	//: Add signal ref
	void add_signal_ref(CL_Signal *signal);

	//: Release signal ref
	void release_signal_ref(CL_Signal *signal);

	//: Sets the persistent flag.
	//- <p>If the slot is persistent, it will remain connected to
	//- signals even when all references to CL_Slot are gone.</p>
	void set_persistent(bool flag = true);

//! Implementation:
private:
	void check_delete();

	bool persistent;

	int slot_ref_count;

	int signal_ref_count;

	std::list<CL_Signal *> connected_signals;
};

#endif
