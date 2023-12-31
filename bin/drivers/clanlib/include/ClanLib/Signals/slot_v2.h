/*  $Id: slot_v2.h,v 1.13 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_slot_v2
#define header_slot_v2

#if _MSC_VER > 1000
#pragma once
#endif

#include "slot_generic.h"

//: Slot V2 Class
//- !group=Signal/System!
//- !header=signals.h!
template <class PARAM1, class PARAM2>
class CL_Slot_v2 : public CL_Slot_Generic
{
public:
	//: Call
	virtual void call(PARAM1 param1, PARAM2 param2)=0;
};

//: FunctionSlot V2 Class
//- !group=Signal/System!
//- !header=signals.h!
template <class PARAM1, class PARAM2>
class CL_FunctionSlot_v2 : public CL_Slot_v2<PARAM1, PARAM2>
{
public:
	typedef void (*Callback)(PARAM1, PARAM2);

	//: FunctionSlot V2 Constructor
	CL_FunctionSlot_v2(Callback callback) : callback(callback) { return; }

	//: Call
	virtual void call(PARAM1 param1, PARAM2 param2) { callback(param1, param2); }

private:
	Callback callback;
};

//: FunctorSlot V2 Class
//- !group=Signal/System!
//- !header=signals.h!
template<class Functor, class PARAM1, class PARAM2>
class CL_FunctorSlot_v2 : public CL_Slot_v2<PARAM1, PARAM2>
{
public:
	//: FunctorSlot V2 Constructor
	CL_FunctorSlot_v2(const Functor &functor)
	: functor(functor) { return; }

	//: Call
	virtual void call(PARAM1 param1, PARAM2 param2) { functor(param1, param2); }

private:
	Functor functor;
};

//: Methane Slot V2 class
//- !group=Signal/System!
//- !header=signals.h!
template <class CallbackClass, class PARAM1, class PARAM2>
class CL_MethodSlot_v2 : public CL_Slot_v2<PARAM1, PARAM2>
{
public:
	typedef void (CallbackClass::*Callback)(PARAM1, PARAM2);

	//: Methane Slot V2 constructor
	CL_MethodSlot_v2(CallbackClass *cb_class, Callback callback)
	: cb_class(cb_class), callback(callback) { return; }

	//: Call
	virtual void call(PARAM1 param1, PARAM2 param2) { (cb_class->*callback)(param1, param2); }

private:
	CallbackClass *cb_class;
	Callback callback;
};

//: User Data Methane Slot V2 Class
//- !group=Signal/System!
//- !header=signals.h!
template <class CallbackClass, class PARAM1, class PARAM2, class UserData>
class CL_UserDataMethodSlot_v2 : public CL_Slot_v2<PARAM1, PARAM2>
{
public:
	typedef void (CallbackClass::*Callback)(PARAM1, PARAM2, UserData);

	//: User Data Methane Slot V2 Constructor
	CL_UserDataMethodSlot_v2(CallbackClass *cb_class, Callback callback, UserData user_data)
	: cb_class(cb_class), callback(callback), user_data(user_data) { return; }

	//: Call
	virtual void call(PARAM1 param1, PARAM2 param2) { (cb_class->*callback)(param1, param2, user_data); }

private:
	CallbackClass *cb_class;
	Callback callback;
	UserData user_data;
};

#endif
