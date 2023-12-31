/*  $Id: thread.h,v 1.22 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_thread
#define header_thread

#if _MSC_VER > 1000
#pragma once
#endif

class CL_Thread_Generic;

//: Thread callback interface.
//- !group=Core/System!
//- !header=core.h!
//- <p>When a thread is created, it will call run() in its attached CL_Runnable interface.</p>
class CL_Runnable
{
//! Construction:
public:
	virtual ~CL_Runnable() { return; }

public:
//! Overrideables:
	//: Called when a thread is run.
	virtual void run()=0;
};

//: Thread Priority Enum
//- !group=Core/System!
//- !header=core.h!
enum EThreadPriority
{
	cl_priority_above_normal,
	cl_priority_below_normal,
	cl_priority_highest,
	cl_priority_idle,
	cl_priority_lowest,
	cl_priority_normal,
	cl_priority_time_critical
};

//: Thread Class
//- !group=Core/System!
//- !header=core.h!
class CL_Thread
{
//! Construction:
public:
	//: Create a thread.
	//param runnable: CL_Runnable object to be used as the thread run function.
	//param delete_runnable: If true, deletes the CL_Runnable object, when CL_Thread is destroyed.
	//param func: Callback function used as the thread run function. Example: int my_callback(void *value).
	//param value: Value parameter passed to callback function.
	CL_Thread(CL_Runnable *runnable, bool delete_runnable = false);

	CL_Thread(int (*func)(void*), void *value);

	CL_Thread(const CL_Thread &copy);

	CL_Thread();
	
	//: Destructor.
	~CL_Thread();
	
//! Attributes:
public:
	//: Returns the thread ID of the calling thread.
	static int get_current_id();
	
//! Operations:
public:
	//: Copy assignement operator.
	CL_Thread &operator =(const CL_Thread &copy);

	//: Starts the thread.
	void start();

	//: Terminate the thread. (use with caution under win98)
	void terminate();

	//: Wait until the thread finishes its execution.
	void wait();

	//: Set the thread priority.
	void set_priority(EThreadPriority priority);

//! Implementation:
private:
	CL_Thread_Generic *impl;
};

#endif
