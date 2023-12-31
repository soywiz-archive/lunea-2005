/*  $Id: threadfunc_v0.h,v 1.5 2003/10/14 15:52:10 mbn Exp $
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
*/

#ifndef header_threadfunc_v0
#define header_threadfunc_v0

#if _MSC_VER > 1000
#pragma once
#endif

#include "thread.h"

template<class Class>
class CL_ThreadFunc_Runnable_v0 : public CL_Runnable
{
public:
	typedef void (Class::*MemberFunc)();

	CL_ThreadFunc_Runnable_v0(Class *self, MemberFunc func)
	: self(self), func(func)
	{
	}

private:
	virtual void run()
	{
		(*self.*func)();
	}

	Class *self;
	MemberFunc func;
};

//: Member function based thread callback interface.
//- <p>The CL_ThreadFunc_v0<MyClass> is an interface used to call a member function
//- in a new thread.</p>
//-
//- Following code demonstrates how it is used:
//- <code>
//- class MyClass
//- {
//-   CL_Thread thread;
//-
//-   MyClass() : thread(CL_ThreadFunc_v0(this, MyClass::worker_function))
//-   {
//-     thread.start();
//-   }
//-
//-   void worker_function() { return; }
//- };
//- </code></p>
#define CL_ThreadFunc_v0(a, b) CL_Thread(new CL_ThreadFunc_Runnable_v0(a, b), true)

/* Following code procudes internal compiler error with msvc++
template<class Class>
CL_Thread CL_ThreadFunc_v0(
	Class *self,
	CL_ThreadFunc_Runnable_v0<Class>::MemberFunc func)
{
	return CL_Thread(new CL_ThreadFunc_Runnable_v0<Class>(self, func), true);
}
*/

#endif
