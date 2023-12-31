/*  $Id: timer.h,v 1.18 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_timer
#define header_timer

#if _MSC_VER > 1000
#pragma once
#endif

#include "keep_alive.h"
#include "../../signals.h"

//: Timer signal emitter.
//- !group=Core/System!
//- !header=core.h!
//- <p>Use this class to emit a signal as a timer event.</p>
class CL_Timer : public CL_KeepAlive
{
//! Construction:
public:
	//: Constructs and registers the timer as a keep alive listener.
	//- <p>Note that it is disabled by default, so you need to enable() it.</p>
	//param interval: Interval in millisecs between each signal emit.
	CL_Timer(unsigned long interval = 1000);
	
//! Attributes:
public:
	//: Returns the current time interval.
	//return: The current time interval.
	unsigned long get_interval();

	//: Returns true if the timer is enabled, false otherwise.
	bool is_enabled();

//! Operations:
public:
	//: Sets a new interval for the timer.
	//param interval: Interval in millisecs between each signal emit.
	void set_interval(unsigned long interval);

	//: Call this function to enable the timer.
	void enable();
	
	//: Call this function to disable the timer.
	void disable();
	
//! Signals:
public:
	//: Signal emitted everytime the interval has elapsed.
	CL_Signal_v0 &sig_timer();
	
//! Implementation:
private:
	virtual void keep_alive();

	unsigned long interval;
	unsigned long last_time;
	bool enabled;

	CL_Signal_v0 signal_timer;
};

#endif
