/*  $Id: slotbuffer_v1.h,v 1.13 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_slotbuffer_v1
#define header_slotbuffer_v1

#if _MSC_VER > 1000
#pragma once
#endif

#include <vector>
#include "slot.h"

template <class PARAM1> class CL_Signal_v1;

//: SlotBuffer V1 Class
//- !group=Signal/System!
//- !header=signals.h!
template <class PARAM1>
class CL_SlotBuffer_v1
{
public:
	struct Params
	{
		PARAM1 p1;
	};

//! Construction:
public:
	//: Slot Buffer V1 Constructor
	CL_SlotBuffer_v1()
	{
	}

	//: Slot Buffer V1 Constructor
	CL_SlotBuffer_v1(CL_Signal_v1<PARAM1> &signal)
	{
		connect(signal);
	}

//! Attributes:
public:
	//: Bool
	operator bool()
	{
		return !params.empty();
	}

	//: Size
	int size()
	{
		return params.size();
	}

	//: Operator
	Params &operator[](int index)
	{
		return params[index];
	}

//! Operations:
public:
	//: Connect
	void connect(CL_Signal_v1<PARAM1> &signal)
	{
		slot = signal.connect(this, &CL_SlotBuffer_v1::callback);
	}

	//: Disconnect
	void disconnect(CL_Signal_v1<PARAM1> &signal)
	{
		signal.disconnect(slot);
	}

//! Implementation:
private:
	void callback(PARAM1 p1)
	{
		Params p;
		p.p1 = p1;

		params.push_back(p);
	}

	std::vector<Params> params;
	CL_Slot slot;
};

#endif
