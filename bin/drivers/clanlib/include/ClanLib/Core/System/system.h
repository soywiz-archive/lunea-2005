/*  $Id: system.h,v 1.18 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_system
#define header_system

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_EventListener;
class CL_Signal_v0;

//: Generic functions that didn't fit in other places.
//- !group=Core/System!
//- !header=core.h!
class CL_System
{
//! Attributes:
public:
	//: Get the current time (since system boot), in milliseconds, including effects of suspend_time()
	static unsigned int get_time();
	
	//: Returns true if MMX technology is available on this CPU.
	static bool detect_mmx();
	
	//: Returns true if 3DNow! technology is available on this CPU.
	static bool detect_3dnow();

	//: Returns true if extended 3DNow! is present on this CPU.
	static bool detect_ext_3dnow();

//! Operations:
public:
	//: Checks for system events, updates input and other stuff.
	static void keep_alive();

	//: Checks for system events (pump the CL_KeepAlive objects).
	//- <p>Return when 'millis' has elapsed.</p>
	static void keep_alive(int millis);

	//: Checks for system events (pump the CL_KeepAlive objects).
	//- <p>Return when one of the events trigger, or when timeout has elapsed.</p>
	static bool keep_alive(CL_EventListener &events, int timeout = -1);

	//: Sleep for 'millis' milliseconds.
	static void sleep(int millis);

	//: Suspend the time.
	//- <p>get_time() will continue to return the same value until resume_time() is called.</p>
	static void suspend_time();

	//: Resumes the time.
	//- <p>get_time() will return the current time again.</p>
	static void resume_time();
	
	//: Returns the full dirname of the executable that started this
	//: process (aka argv[0])
	//- <p>This is necessary since when programms are started from
	//- the PATH there is no clean and simple way to figure out
	//- the location of the data files, thus information is read
	//- from <tt>/proc/self/exe</tt> under GNU/Linux and from
	//- GetModuleFileName() on Win32.</p>
        //return: full dirname of the executable, trailing slash is included
	static std::string get_exe_path();

//! Implementation:
private:
	//Starting sys_time() of the least recently started but still active suspend
	static unsigned int susp_start;

	//Number of active suspends
	static unsigned int susp_cnt;

	//Time taken up by suspends that occurred before
	static unsigned int susp_accum;
	
	//Done by platform-specific stuff, returns the cur time without dealing with any of this suspend/resume stuff
	static unsigned int sys_time();
};

#endif
