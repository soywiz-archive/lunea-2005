/*  $Id: slot_container.h,v 1.20 2004/01/22 13:28:07 mbn Exp $
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

//! clanSignal="System"
//! header=signals.h

#ifndef header_slot_container
#define header_slot_container

#if _MSC_VER > 1000
#pragma once
#endif

#include "slot.h"
#include "signal_v0.h"
#include "signal_v1.h"
#include "signal_v2.h"
#include "signal_v3.h"
#include "signal_v4.h"
#include "signal_v5.h"
#include <list>

//: Slot Generic Container
//- !group=Signal/System!
//- !header=signals.h!
//- <p>Convience signal/slot connector class.</p>
//- <p>The slot container class is a convience class. It simplifies the
//- connection between signals and slots by keeping all connections made
//- until the entire class is destroyed. This saves the developer from having
//- to keep a CL_Slot reference around for each connection needed.</p>
//- <p>In order to use this class, simply make it a member variable and call
//- connect_signal() for each function you want hooked up.</p>
//- <p>See the login_view.cpp/h in the CTalk example for an example of how to use
//- this class.</p>
class CL_SlotContainer
{
public:
//! Operations:
	//: Connect a slot to a CL_Signal_v0 signal.
	template<class SigClass>
	void connect(SigClass &sig, void (*func)())
	{
		slots.push_back(sig.connect(func));
	}

	//: Connect a slot to a CL_Signal_v0 signal.
	template<class SigClass, class Class>
	void connect(SigClass &sig, Class *self, void(Class::*func)())
	{
		slots.push_back(sig.connect(self, func));
	}

	//: Connect a slot to a CL_Signal_v0 signal with an user data parameter
	//: passed along.
	template<class SigClass, class Class, class UserData>
	void connect(SigClass &sig, Class *self, void(Class::*func)(UserData), UserData user_data)
	{
		slots.push_back(sig.connect(self, func, user_data));
	}

	//: Connect a slot to a CL_Signal_v1 signal.
	template<class SigClass, class Class, class Param1>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1))
	{
		slots.push_back(sig.connect(self, func));
	}

	//: Connect a slot to a CL_Signal_v1 signal with an user data parameter
	//: passed along.
	template<class SigClass, class Class, class Param1, class UserData>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1, UserData), UserData user_data)
	{
		slots.push_back(sig.connect(self, func, user_data));
	}

	//: Connect a slot to a CL_Signal_v2 signal.
	template<class SigClass, class Class, class Param1, class Param2>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1, Param2))
	{
		slots.push_back(sig.connect(self, func));
	}

	//: Connect a slot to a CL_Signal_v2 signal with an user data parameter
	//: passed along.
	template<class SigClass, class Class, class Param1, class Param2, class UserData>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1, Param2, UserData), UserData user_data)
	{
		slots.push_back(sig.connect(self, func, user_data));
	}

	//: Connect a slot to a CL_Signal_v3 signal.
	template<class SigClass, class Class, class Param1, class Param2, class Param3>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1, Param2, Param3))
	{
		slots.push_back(sig.connect(self, func));
	}

	//: Connect a slot to a CL_Signal_v3 signal with an user data parameter
	//: passed along.
	template<class SigClass, class Class, class Param1, class Param2, class Param3, class UserData>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1, Param2, Param3, UserData), UserData user_data)
	{
		slots.push_back(sig.connect(self, func, user_data));
	}

	//: Connect a slot to a CL_Signal_v4 signal.
	template<class SigClass, class Class, class Param1, class Param2, class Param3, class Param4>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1, Param2, Param3, Param4))
	{
		slots.push_back(sig.connect(self, func));
	}

	//: Connect a slot to a CL_Signal_v4 signal with an user data parameter
	//: passed along.
	template<class SigClass, class Class, class Param1, class Param2, class Param3, class Param4, class UserData>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1, Param2, Param3, Param4, UserData user_data), UserData user_data)
	{
		slots.push_back(sig.connect(self, func, user_data));
	}

	//: Connect a slot to a CL_Signal_v5 signal.
	template<class SigClass, class Class, class Param1, class Param2, class Param3, class Param4, class Param5>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1, Param2, Param3, Param4, Param5))
	{
		slots.push_back(sig.connect(self, func));
	}

	//: Connect a slot to a CL_Signal_v5 signal with an user data parameter
	//: passed along.
	template<class SigClass, class Class, class Param1, class Param2, class Param3, class Param4, class Param5, class UserData>
	void connect(SigClass &sig, Class *self, void(Class::*func)(Param1, Param2, Param3, Param4, Param5, UserData user_data), UserData user_data)
	{
		slots.push_back(sig.connect(self, func, user_data));
	}

	//: Connect a functor slot to a signal.
	template<class SigClass, class Functor>
	void connect_functor(SigClass &sig, const Functor &functor)
	{
		slots.push_back(sig.connect_functor(functor));
	}

private:
	std::list<CL_Slot> slots;
};

#endif
