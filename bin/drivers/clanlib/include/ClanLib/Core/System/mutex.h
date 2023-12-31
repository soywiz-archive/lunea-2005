/*  $Id: mutex.h,v 1.17 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_mutex
#define header_mutex

#if _MSC_VER > 1000
#pragma once
#endif

class CL_Mutex_Generic;

//: Mutex interface.
//- !group=Core/System!
//- !header=core.h!
//- <p>If you don't know what a mutex is, read a book. :-)</p>
class CL_Mutex
{
public:
//! Construction:
	//: Call this to create a mutex. (provided for 0.4 backward compatibility)
	static CL_Mutex *create();

	//: Construct a new mutex.
	CL_Mutex();

	//: Destroy mutex.
	~CL_Mutex();
	
//! Operations:
	//: Enter the critical section.
	void enter();

	//: Leave the critical section.
	void leave();

	//: Releases the mutex this thread has taken out and sends the
	//: thread to sleep.
	//- <p>Other threads can then acquire the mutex and
	//- modify any data. When another thread calls notify, the thread
	//- that called wait will wake up again and automatically reacquire
	//- the mutex.</p>
	//-
	//- <p>Warning: This function must not be called on an unlocked 
	//- mutex. You must call enter first.</p>
	//-
	//- <p>Warning: When wait returns (after another thread has called
	//- notify/notifyAll, the current thread will have a mutex lock. Be
	//- sure to call leave at some point.</p>
	//-
	//- <p>Warning: Not implemented under Win32. If you need it,
	//- please implement it in Sources/Core/System/Win32/mutex_win32.*,
	//- and send me the patch. :-)</p>
	void wait();

	//: Notify wakes up the first thread that has gone to sleep on this
	//: mutex in order to wait for a notification.
	//- <p>For safety reasons, you are advised to acquire the mutex
	//- using 'enter' before calling notify. (Of course you have to
	//- release the mutex using 'leave' after notifying, otherwise the
	//- waiting thread cannot reacquire it).</p>
	//-
	//- <p>Warning: Not implemented under Win32. If you need it,
	//- please implement it in Sources/Core/System/Win32/mutex_win32.*,
	//- and send me the patch. :-)</p>
	void notify();

	//: NotifyAll wakes up all threads waiting on the mutex.
	//- <p>Warning: Not implemented under Win32. If you need it,
	//- please implement it in Sources/Core/System/Win32/mutex_win32.*,
	//- and send me the patch. :-)</p>
	//also: CL_Mutex::notify
	void notify_all();

private:
	// Disallow copy construction.
	CL_Mutex(const CL_Mutex &copy);

	// Disallow mutex copy assignment.
	void operator =(const CL_Mutex &copy);

	CL_Mutex_Generic *impl;
};

//: Lock a mutex until the end of a scope.
//- <p>This class is a way to ensure a mutex will be released at the end of 
//- a scope. When an instance is constructed, it will lock the mutex, and
//- when the instance is destroyed (at the exit of its scope), it will
//- unlock the mutex.</p>
class CL_MutexSection
{
//! Construction:
public:
	//: Mutex Section constructor.
	CL_MutexSection(CL_Mutex *mutex, bool lock_at_construct = true)
	: mutex(mutex), lock_count(0)
	{
		if (lock_at_construct) enter();
	}

	//: Mutex Section destructor.
	virtual ~CL_MutexSection()
	{
		while (lock_count > 0) leave();
	}

//! Operations:
public:
	//: Lock mutex.
	void enter()
	{
		mutex->enter();
		lock_count++;
	}

	//: Unlock mutex.
	void leave()
	{
		if (lock_count == 0) return;
		mutex->leave();
		lock_count--;
	}

//! Implementation:
private:
	CL_Mutex *mutex;

	int lock_count;
};

#endif
