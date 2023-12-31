/*  $Id: slot_v1.h,v 1.13 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_slot_v1
#define header_slot_v1

#if _MSC_VER > 1000
#pragma once
#endif

#include "slot_generic.h"

//: Slot V1 class
//- !group=Signal/System!
//- !header=signals.h!
template <class PARAM1>
class CL_Slot_v1 : public CL_Slot_Generic
{
public:
	//: Call
	virtual void call(PARAM1 param1)=0;
};

//: Funtion Slot V1 class
//- !group=Signal/System!
//- !header=signals.h!
template <class PARAM1>
class CL_FunctionSlot_v1 : public CL_Slot_v1<PARAM1>
{
public:
	typedef void (*Callback)(PARAM1);

	//: Funtion Slot V1 constructor
	CL_FunctionSlot_v1(Callback callback) : callback(callback) { return; }

	//: Call
	virtual void call(PARAM1 param1) { callback(param1); }

private:
	Callback callback;
};

//: FunctorSlot V1 Class
//- !group=Signal/System!
//- !header=signals.h!
template<class Functor, class PARAM1>
class CL_FunctorSlot_v1 : public CL_Slot_v1<PARAM1>
{
public:
	//: FunctorSlot V1 Constructor
	CL_FunctorSlot_v1(const Functor &functor)
	: functor(functor) { return; }

	//: Call
	virtual void call(PARAM1 param1) { functor(param1); }

private:
	Functor functor;
};

//: Method Slot V1
//- !group=Signal/System!
//- !header=signals.h!
template <class CallbackClass, class PARAM1>
class CL_MethodSlot_v1 : public CL_Slot_v1<PARAM1>
{
public:
	typedef void (CallbackClass::*Callback)(PARAM1);

	//: Method Slot V1 constructor
	CL_MethodSlot_v1(CallbackClass *cb_class, Callback callback)
	: cb_class(cb_class), callback(callback) { return; }

	//: Call
	virtual void call(PARAM1 param1) { (cb_class->*callback)(param1); }

private:
	CallbackClass *cb_class;
	Callback callback;
};

//: User Data Method Slot V1 class
//- !group=Signal/System!
//- !header=signals.h!
template <class CallbackClass, class PARAM1, class UserData>
class CL_UserDataMethodSlot_v1 : public CL_Slot_v1<PARAM1>
{
public:
	typedef void (CallbackClass::*Callback)(PARAM1, UserData);

	//: User Data Method Slot V1 constructor
	CL_UserDataMethodSlot_v1(CallbackClass *cb_class, Callback callback, UserData user_data)
	: cb_class(cb_class), callback(callback), user_data(user_data) { return; }

	//: Call
	virtual void call(PARAM1 param1) { (cb_class->*callback)(param1, user_data); }

private:
	CallbackClass *cb_class;
	Callback callback;
	UserData user_data;
};

#endif
