/*  $Id: slot_v0.h,v 1.16 2004/01/13 15:10:06 mbn Exp $
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

#ifndef header_slot_v0
#define header_slot_v0

#if _MSC_VER > 1000
#pragma once
#endif

#include "slot_generic.h"
#include <list>

//: Slot V0 Class
//- !group=Signal/System!
//- !header=signals.h!
class CL_Slot_v0 : public CL_Slot_Generic
{
public:
	//: Call
	virtual void call(class CL_SlotParent_v0 &super)=0;
};

//: Slot Parent V0 Class
//- !group=Signal/System!
//- !header=signals.h!
class CL_SlotParent_v0
{
public:
	typedef CL_Slot_v0 *Slot;
	typedef std::list<Slot>::iterator SlotIterator;

//! Construction:
public:
	
	//: Slot Parent V0 Constructor
	CL_SlotParent_v0(const SlotIterator &pos, const SlotIterator &end)
	: pos(pos), end(end)
	{
	}

//! Operations:
public:
	//: Operator
	void operator() ()
	{
		if (pos == end) return;

		SlotIterator next = pos;
		next++;

		if ((*pos)->get_slot_ref() > 0)
		{
			CL_SlotParent_v0 super(next, end);
			(*pos)->call(super);
		}
	}

//! Implementation:
private:
	SlotIterator pos, end;
};

//: FunctionSlot V0 Class
//- !group=Signal/System!
//- !header=signals.h!
class CL_FunctionSlot_v0 : public CL_Slot_v0
{
public:
	typedef void (*Callback)();
	typedef void (*VirtualCallback)(CL_SlotParent_v0 &);

	//: FunctionSlot V0 Constructor
	CL_FunctionSlot_v0(Callback callback, VirtualCallback virtual_callback)
	: callback(callback), virtual_callback(virtual_callback) { return; }

	//: Call
	virtual void call(CL_SlotParent_v0 &super)
	{
		if (callback) { super(); callback(); }
		else virtual_callback(super);
	}

private:
	Callback callback;
	VirtualCallback virtual_callback;
};

//: FunctorSlot V0 Class
//- !group=Signal/System!
//- !header=signals.h!
template<class Functor>
class CL_FunctorSlot_v0 : public CL_Slot_v0
{
public:
	//: FunctorSlot V0 Constructor
	CL_FunctorSlot_v0(const Functor &functor)
	: functor(functor) { return; }

	//: Call
	virtual void call(CL_SlotParent_v0 &super)
	{
		super();
		functor();
	}

private:
	Functor functor;
};

//: FunctorSlot V0 Class
//- !group=Signal/System!
//- !header=signals.h!
template<class Functor>
class CL_FunctorVirtualSlot_v0 : public CL_Slot_v0
{
public:
	//: FunctorVirtualSlot V0 Constructor
	CL_FunctorVirtualSlot_v0(const Functor &functor)
	: functor(functor) { return; }

	//: Call
	virtual void call(CL_SlotParent_v0 &super)
	{
		functor(super);
	}

private:
	Functor functor;
};

//: Method Slot V0 Class
//- !group=Signal/System!
//- !header=signals.h!
template <class CallbackClass>
class CL_MethodSlot_v0 : public CL_Slot_v0
{
public:
	typedef void (CallbackClass::*Callback)();
	typedef void (CallbackClass::*VirtualCallback)(CL_SlotParent_v0 &);

	//: Method Slot V0 Constructor
	CL_MethodSlot_v0(CallbackClass *cb_class, Callback callback, VirtualCallback virtual_callback)
	: cb_class(cb_class), callback(callback), virtual_callback(virtual_callback) { return; }

	//: Call
	virtual void call(CL_SlotParent_v0 &super)
	{
		if (callback) { super(); (cb_class->*callback)(); }
		else (cb_class->*virtual_callback)(super);
	}

private:
	CallbackClass *cb_class;
	Callback callback;
	VirtualCallback virtual_callback;
};

//: User Data Methane Slot V0 Class
//- !group=Signal/System!
//- !header=signals.h!
template <class CallbackClass, class UserData>
class CL_UserDataMethodSlot_v0 : public CL_Slot_v0
{
public:
	typedef void (CallbackClass::*Callback)(UserData);
	typedef void (CallbackClass::*VirtualCallback)(CL_SlotParent_v0 &, UserData);

	//: User Data Methane Slot V0 Constructor
	CL_UserDataMethodSlot_v0(CallbackClass *cb_class, Callback callback, VirtualCallback virtual_callback, UserData user_data)
	: cb_class(cb_class), callback(callback), virtual_callback(virtual_callback), user_data(user_data) { return; }

	//: Call
	virtual void call(CL_SlotParent_v0 &super)
	{
		if (callback) { super(); (cb_class->*callback)(user_data); }
		else (cb_class->*virtual_callback)(super, user_data);
	}

private:
	CallbackClass *cb_class;
	Callback callback;
	VirtualCallback virtual_callback;
	UserData user_data;
};

#endif
