/*  $Id: threadfunc_v1.h,v 1.5 2003/10/14 15:52:10 mbn Exp $
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

#ifndef header_threadfunc_v1
#define header_threadfunc_v1

#if _MSC_VER > 1000
#pragma once
#endif

#include "thread.h"

template<class Class, class Param>
class CL_ThreadFunc_Runnable_v1 : public CL_Runnable
{
public:
	typedef void (Class::*MemberFunc)(Param &param);

	CL_ThreadFunc_Runnable_v1(Class *self, MemberFunc func, const Param &param)
	: self(self), func(func), param(param)
	{
	}

private:
	virtual void run()
	{
		(*self.*func)(param);
	}

	Class *self;
	MemberFunc func;
	Param param;
};

//: Member function based thread callback interface.
//- <p>The CL_ThreadFunc_v1<MyClass, MyParam> is an interface used to call a member function
//- in a new thread.</p>
//-
//- <p>Following code demonstrates how it is used:
//- <code>
//- class MyClass
//- {
//-   CL_Thread thread;
//-
//-   MyClass() : thread(CL_ThreadFunc_v1(this, MyClass::worker_function, 15))
//-   {
//-     thread.start();
//-   }
//-
//-   void worker_function(int value) { assert(value == 15); }
//- };
//- </code></p>
#define CL_ThreadFunc_v1(a, b, c) CL_Thread(new CL_ThreadFunc_Runnable_v1(a, b, c), true)

/* Following code procudes internal compiler error with msvc++
template<class Class, class Param>
CL_Thread CL_ThreadFunc_v1(
	Class *self,
	CL_ThreadFunc_Runnable_v1<Class, Param>::MemberFunc func,
	const Param &param)
{
	return CL_Thread(new CL_ThreadFunc_Runnable_v1<Class, Param>(self, func, param), true);
}
*/

#endif
