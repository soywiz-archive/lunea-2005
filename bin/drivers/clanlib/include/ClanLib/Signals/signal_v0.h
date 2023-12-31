/*  $Id: signal_v0.h,v 1.24 2004/04/15 11:08:57 mbn Exp $
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

#ifndef header_signal_v0
#define header_signal_v0

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning ( disable : 4786 )
#pragma warning ( disable : 4355 ) // warning C4355: 'this' : used in base member initializer list
#endif

#include "signal.h"
#include "slot.h"
#include "slot_v0.h"
#include <list>
#include <algorithm>

//: CL Signal v0 class
//- !group=Signal/System!
//- !header=signals.h!
class CL_Signal_v0 : public CL_Signal
{
public:
	typedef CL_Slot_v0 *Slot;
	typedef std::list<Slot>::iterator SlotIterator;

	class CL_Signal_v0_Generic
	{
	public:
		CL_Signal_v0_Generic(CL_Signal_v0 *owner) : in_call(false), deleted(false), in_call_remove_slots(0), owner(owner) { return; }

		~CL_Signal_v0_Generic()
		{
			for (SlotIterator slot_it = slots.begin(); slot_it != slots.end(); slot_it++)
			{
				Slot slot = *slot_it;
				slot->release_signal_ref(owner);
			}
		}

		bool in_call, deleted;
		std::list<SlotIterator> *in_call_remove_slots;
		std::list<Slot> slots;
		CL_Signal_v0 *owner;
	};

//! Construction:
public:
	//: CL Signal v0 constructor
	CL_Signal_v0() : impl(new CL_Signal_v0_Generic(this))
	{
	}

	CL_Signal_v0(const CL_Signal_v0 &copy) : impl(new CL_Signal_v0_Generic(this))
	{
		impl->slots = copy.impl->slots;
		for (SlotIterator slot_it = impl->slots.begin(); slot_it != impl->slots.end(); slot_it++)
		{
			Slot slot = *slot_it;
			slot->add_signal_ref(this);
		}
	}

	//: CL Signal v0 destructor
	~CL_Signal_v0()
	{
		if (impl->in_call) impl->deleted = true;
		else delete impl;
	}

//! Operations:
public:
	CL_Signal_v0 &operator =(const CL_Signal_v0 &copy)
	{
		if (impl->in_call) impl->deleted = true;
		else delete impl;

		impl = new CL_Signal_v0_Generic(this);
		impl->slots = copy.impl->slots;
		for (SlotIterator slot_it = impl->slots.begin(); slot_it != impl->slots.end(); slot_it++)
		{
			Slot slot = *slot_it;
			slot->add_signal_ref(this);
		}
		return *this;
	}

	//: Operator
	void operator() ()
	{
		call();
	}

	//: Call
	void call()
	{
		CL_Signal_v0_Generic *data = impl;
		data->in_call = true;

		std::list<SlotIterator> remove_slots;
		try
		{
			data->in_call_remove_slots = &remove_slots;

			// call slots connected to signal:
			CL_SlotParent_v0 super(data->slots.begin(), data->slots.end());
			super();
		}
		catch(...)
		{
			catch_final(data, remove_slots);
			throw;
		}

		catch_final(data, remove_slots);
	}

	//: Connect slot.
	CL_Slot connect(Slot slot)
	{
		slot->add_signal_ref(this);
		impl->slots.push_front(slot);
		return CL_Slot(slot);
	}

	//: Connect callback function slot.
	CL_Slot connect(void (*callback)())
	{
		return connect(new CL_FunctionSlot_v0(callback, 0));
	}

	//: Connect virtual callback function slot.
	CL_Slot connect_virtual(void (*virtual_callback)(CL_SlotParent_v0 &))
	{
		return connect(new CL_FunctionSlot_v0(0, virtual_callback));
	}

	//: Connect functor slot.
	template<class Functor>
	CL_Slot connect_functor(const Functor &functor)
	{
		return connect(new CL_FunctorSlot_v0<Functor>(functor));
	}

	//: Connect virtual functor slot.
	template<class Functor>
	CL_Slot connect_functor_virtual(const Functor &functor)
	{
		return connect(new CL_FunctorVirtualSlot_v0<Functor>(functor));
	}

	//: Connect member function slot.
	template <class CallbackClass>
	CL_Slot connect(CallbackClass *cb_class, void (CallbackClass::*callback)())
	{
		return connect(new CL_MethodSlot_v0<CallbackClass>(cb_class, callback, 0));
	}

	//: Connect virtual member function slot.
	template <class CallbackClass>
	CL_Slot connect_virtual(CallbackClass *cb_class, void (CallbackClass::*virtual_callback)(CL_SlotParent_v0 &))
	{
		return connect(new CL_MethodSlot_v0<CallbackClass>(cb_class, 0, virtual_callback));
	}

	//: Connect member function with user data slot.
	template <class CallbackClass, class UserData>
	CL_Slot connect(
		CallbackClass *cb_class,
		void (CallbackClass::*callback)(UserData),
		UserData user_data)
	{
		return connect(new CL_UserDataMethodSlot_v0<CallbackClass, UserData>(cb_class, callback, 0, user_data));
	}

	//: Create virtual member function with user data slot.
	template <class CallbackClass, class UserData>
	CL_Slot connect_virtual(
		CallbackClass *cb_class,
		void (CallbackClass::*virtual_callback)(CL_SlotParent_v0 &, UserData),
		UserData user_data)
	{
		return connect(new CL_UserDataMethodSlot_v0<CallbackClass, UserData>(cb_class, 0, virtual_callback, user_data));
	}

	//: Disconnect
	void disconnect(CL_Slot &disconnect_slot)
	{
		for (SlotIterator slot_it = impl->slots.begin(); slot_it != impl->slots.end();)
		{
			Slot slot = *slot_it;
			if (disconnect_slot.impl == slot)
			{
				if (impl->in_call)
				{
					impl->in_call_remove_slots->push_back(slot_it);
					++slot_it;
				}
				else
				{
					slot->release_signal_ref(this);
					slot_it = impl->slots.erase(slot_it);
				}
			}
			else
				++slot_it;
		}
	}

//! Implementation:
private:
	void catch_final(CL_Signal_v0_Generic *data, std::list<SlotIterator> &remove_slots)
	{
		data->in_call_remove_slots = 0;

		// find slots to be removed:
		for (SlotIterator slot_it = data->slots.begin(); slot_it != data->slots.end(); slot_it++)
		{
			Slot slot = *slot_it;

			// skip slot if it has no more references left in application.
			// (make it pending for removal)
			if (slot->get_slot_ref() == 0 && slot->is_persistent() == false)
			{
				if (std::find(remove_slots.begin(), remove_slots.end(), slot_it)==remove_slots.end())
					remove_slots.push_back(slot_it);
			}
		}

		// remove all slots no longer connected to any CL_Slot.
		std::list<SlotIterator>::iterator remove_it;
		for (remove_it = remove_slots.begin(); remove_it != remove_slots.end(); remove_it++)
		{
			Slot slot = **remove_it;
			slot->release_signal_ref(this);
			data->slots.erase(*remove_it);
		}

		data->in_call = false;
		if (data->deleted) delete data;
	}

	CL_Signal_v0_Generic *impl;
};

#endif
