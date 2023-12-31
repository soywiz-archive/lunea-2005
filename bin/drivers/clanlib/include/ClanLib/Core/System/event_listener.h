/*  $Id: event_listener.h,v 1.22 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_event_listener
#define header_event_listener

#if _MSC_VER > 1000
#pragma once
#endif

class CL_EventTrigger;
class CL_EventListener_Generic;

//: Event listening interace.
//- !group=Core/System!
//- !header=core.h!
//- <p>The event listener is used to collect a set of events, identified as CL_EventTrigger,
//- and wait for one of them to occur. This is analog to the low level C socket select()
//- function, except that this one operates on clanlib objects.</p>
class CL_EventListener
{
//! Construction:
public:
	//: Constructs an event listener object.
	//param trigger: Initial trigger to be added to listener.
	CL_EventListener();

	CL_EventListener(CL_EventTrigger *trigger);

	//: Event Listener destructor.
	virtual ~CL_EventListener();

//! Attributes:
public:

//! Operations:
public:
	//: Adds an event trigger to the listener.
	void add_trigger(CL_EventTrigger *trigger);

	//: Removes an event trigger from the listener.
	void remove_trigger(CL_EventTrigger *trigger);

	//: Removes all event triggers from the listener.
	void clear();

	//: Resets all event triggers added to the listener.
	void reset_all();

	//: Wait until one of the events triggers.
	//param timeout - The timeout is in milliseconds. If -1, waits infinitely.
	//- <p>If timeout = -1, this function will not timeout.</p>
	//returns: True if an event triggered, false if it timed out.
	bool wait(int timeout = -1);

//! Implementation:
private:
	CL_EventListener_Generic *impl;
};

#endif
