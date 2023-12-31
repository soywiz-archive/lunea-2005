/*  $Id: threadfunc_v2.h,v 1.5 2003/10/14 15:52:10 mbn Exp $
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

#ifndef header_threadfunc_v2
#define header_threadfunc_v2

#if _MSC_VER > 1000
#pragma once
#endif

#include "thread.h"

template<class Class, class Param1, class Param2>
class CL_ThreadFunc_Runnable_v2 : public CL_Runnable
{
public:
	typedef void (Class::*MemberFunc)(Param1 &param1, Param2 &param2);

	CL_ThreadFunc_Runnable_v2(Class *self, MemberFunc func, const Param1 &param1, const Param2 &param2)
	: self(self), func(func), param1(param1), param2(param2)
	{
	}

private:
	virtual void run()
	{
		(*self.*func)(param1, param2);
	}

	Class *self;
	MemberFunc func;
	Param1 param1;
	Param2 param2;
};

//: Member function based thread callback interface.
//- <p>The CL_ThreadFunc_v2<MyClass, MyParam1, MyParam2> is an interface used to call a member function
//- in a new thread.</p>
//-
//- <p>Following code demonstrates how it is used:
//- <code>
//- class MyClass
//- {
//-   CL_Thread thread;
//-
//-   MyClass() : thread(CL_ThreadFunc_v2(this, MyClass::worker_function, 15, 16))
//-   {
//-     thread.start();
//-   }
//-
//-   void worker_function(int value1, int value2) { assert(value1 == 15 && value2 == 16); }
//- };
//- </code></p>
#define CL_ThreadFunc_v2(a, b, c, d) CL_Thread(new CL_ThreadFunc_Runnable_v1(a, b, c, d), true)

/* Following code procudes internal compiler error with msvc++
template<class Class, class Param1, class Param2>
CL_Thread CL_ThreadFunc_v2(
	Class *self,
	CL_ThreadFunc_Runnable_v2<Class, Param1, Param2>::MemberFunc func,
	const Param1 &param1,
	const Param2 &param2)
{
	return CL_Thread(new CL_ThreadFunc_Runnable_v2<Class, Param1, Param2>(self, func, param1, param2), true);
}
*/

#endif
