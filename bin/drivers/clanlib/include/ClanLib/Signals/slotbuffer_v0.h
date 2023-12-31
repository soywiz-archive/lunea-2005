/*  $Id: slotbuffer_v0.h,v 1.12 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_slotbuffer_v0
#define header_slotbuffer_v0

#if _MSC_VER > 1000
#pragma once
#endif

#include "signal_v0.h"

//: Slot Buffer V0 Class
//- !group=Signal/System!
//- !header=signals.h!
class CL_SlotBuffer_v0
{
//! Construction:
public:
	//: Slot Buffer V0 Constructor
	CL_SlotBuffer_v0() : count(0)
	{
	}

	//: Slot Buffer V0 Constructor
	CL_SlotBuffer_v0(CL_Signal_v0 &signal) : count(0)
	{
		connect(signal);
	}

//! Attributes:
public:
	//: Bool
	operator bool()
	{
		return count > 0;
	}

	//: Size
	int size()
	{
		return count;
	}

//! Operations:
public:
	//: Connect
	void connect(CL_Signal_v0 &signal)
	{
		slot = signal.connect(this, &CL_SlotBuffer_v0::callback);
	}

	//: Disconnect
	void disconnect(CL_Signal_v0 &signal)
	{
		signal.disconnect(slot);
	}

//! Implementation:
private:
	void callback()
	{
		count++;
	}

	CL_Slot slot;
	int count;
};

#endif
