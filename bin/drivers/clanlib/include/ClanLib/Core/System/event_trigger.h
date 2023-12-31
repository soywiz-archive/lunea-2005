/*  $Id: event_trigger.h,v 1.20 2004/02/01 03:07:16 mbn Exp $
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

#ifndef header_event_trigger
#define header_event_trigger

#if _MSC_VER > 1000
#pragma once
#endif

#include "sharedptr.h"

class CL_EventListener;
class CL_EventTrigger_Generic;

//: ClanLib Event trigger.
//- !group=Core/System!
//- !header=core.h!
//- <p>This class represents an event that can be triggered.</p>
//- <p>Collect several triggers together using the CL_EventListener class, and then
//- call the CL_EventListener::wait function to sleep until one of the events
//- are triggered.</p>
class CL_EventTrigger
{
//! Construction:
public:
	//: Constructs an event trigger object.
	CL_EventTrigger();

	CL_EventTrigger(const CL_EventTrigger &copy);

	//: Event Trigger destructor.
	virtual ~CL_EventTrigger();

//! Attributes:
public:
	//: Returns true if the trigger flag has been raised.
	bool get_flag() const;

//! Operations:
public:
	//: Reset trigger flag.
	void reset() const;

	//: Raise trigger flag.
	void set_flag();

	//: Wait until the event triggers.
	//param timeout - The timeout is in milliseconds. If -1, waits infinitely.
	//- <p>If timeout = -1, this function will not timeout.</p>
	//returns: True if event triggered, false if it timed out.
	bool wait(int timeout = -1);

//! Implementation:
public:
	CL_SharedPtr<CL_EventTrigger_Generic> impl;
};

#endif
