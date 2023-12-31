/*  $Id: signal.h,v 1.1 2004/01/28 01:17:37 mbn Exp $
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

#ifndef header_signal
#define header_signal

#if _MSC_VER > 1000
#pragma once
#endif

class CL_Slot;

//: Parent class for all signal types.
class CL_Signal
{
//! Construction:
public:
	virtual ~CL_Signal() { return; }

//! Operations:
public:
	//: Disconnect
	virtual void disconnect(CL_Slot &disconnect_slot)=0;
};

#endif
