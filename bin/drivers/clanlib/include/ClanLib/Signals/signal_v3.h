/*  $Id: signal_v3.h,v 1.26 2004/04/20 21:50:23 harry Exp $
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

#ifndef header_signal_v3
#define header_signal_v3

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning ( disable : 4786 )
#pragma warning ( disable : 4355 ) // warning C4355: 'this' : used in base member initializer list
#endif

#include "signal.h"
#include "slot.h"
#include "slot_v3.h"
#include <list>

//: Signal V3 Class
//- !group=Signal/System!
//- !header=signals.h!
template <class PARAM1, class PARAM2, class PARAM3>
class CL_Signal_v3 : public CL_Signal
{
public:
	typedef CL_Slot_v3<PARAM1, PARAM2, PARAM3> *Slot;
	typedef typename std::list<Slot>::iterator SlotIterator;

	class CL_Signal_v3_Generic
	{
	public:
		CL_Signal_v3_Generic(CL_Signal_v3 *owner) : in_call(false), deleted(false), in_call_remove_slots(0), owner(owner) { return; }

		~CL_Signal_v3_Generic()
		{
			for (SlotIterator slot_it = slots.begin(); slot_it != slots.end(); slot_it++)
			{
				Slot slot = *slot_it;
				slot->release_signal_ref(this->owner);
			}
		}

		bool in_call, deleted;
		std::list<SlotIterator> *in_call_remove_slots;
		std::list<Slot> slots;
		CL_Signal_v3 *owner;
	};

//! Construction:
public:
	//: Signal V3 Constructor
	CL_Signal_v3() : impl(new CL_Signal_v3_Generic(this))
	{
	}

	CL_Signal_v3(const CL_Signal_v3 &copy) : impl(new CL_Signal_v3_Generic(this))
	{
		impl->slots = copy.impl->slots;
		for (SlotIterator slot_it = impl->slots.begin(); slot_it != impl->slots.end(); slot_it++)
		{
			Slot slot = *slot_it;
			slot->add_signal_ref(this->owner);
		}
	}

	//: Signal V3 Destructor
	~CL_Signal_v3()
	{
		if (impl->in_call) impl->deleted = true;
		else delete impl;
	}

//! Attributes:
public:
	bool has_slots_connected() const
	{
		return !impl->slots.empty();
	}

//! Operations:
public:
	CL_Signal_v3 &operator =(const CL_Signal_v3 &copy)
	{
		if (impl->in_call) impl->deleted = true;
		else delete impl;

		impl = new CL_Signal_v3_Generic(this);
		impl->slots = copy.impl->slots;
		for (SlotIterator slot_it = impl->slots.begin(); slot_it != impl->slots.end(); slot_it++)
		{
			Slot slot = *slot_it;
			slot->add_signal_ref(this);
		}
		return *this;
	}

	//: Operator
	void operator() (PARAM1 param1, PARAM2 param2, PARAM3 param3)
	{
		call(param1, param2, param3);
	}

	//: Call
	void call(PARAM1 param1, PARAM2 param2, PARAM3 param3)
	{
		CL_Signal_v3_Generic *data = impl;
		data->in_call = true;

		std::list<SlotIterator> remove_slots;
		try
		{
			data->in_call_remove_slots = &remove_slots;

			// call slots connected to signal:
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
			
				slot->call(param1, param2, param3);
				if (data->deleted) break;
			}
		}
		catch (...)
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
		impl->slots.push_back(slot);
		return CL_Slot(slot);
	}

	//: Connect callback function slot.
	CL_Slot connect(void (*callback)(PARAM1, PARAM2, PARAM3))
	{
		return connect(new CL_FunctionSlot_v3<PARAM1,PARAM2,PARAM3>(callback));
	}

	//: Connect functor slot.
	template<class Functor>
	CL_Slot connect_functor(const Functor &functor)
	{
		return connect(new CL_FunctorSlot_v3<Functor, PARAM1, PARAM2, PARAM3>(functor));
	}

	//: Connect member function slot.
	template <class CallbackClass>
	CL_Slot connect(
		CallbackClass *cb_class,
		void (CallbackClass::*callback)(PARAM1, PARAM2, PARAM3))
	{
		return connect(new CL_MethodSlot_v3<CallbackClass, PARAM1, PARAM2, PARAM3>(cb_class, callback));
	}

	//: Connect member function with user data slot.
	template <class CallbackClass, class UserData>
	CL_Slot connect(
		CallbackClass *cb_class,
		void (CallbackClass::*callback)(PARAM1, PARAM2, PARAM3, UserData),
		UserData user_data)
	{
		return connect(new CL_UserDataMethodSlot_v3<CallbackClass, PARAM1, PARAM2, PARAM3, UserData>(cb_class, callback, user_data));
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
	void catch_final(CL_Signal_v3_Generic *data, std::list<SlotIterator> &remove_slots)
	{
		data->in_call_remove_slots = 0;

		// remove all slots no longer connected to any CL_Slot.
		typename std::list<SlotIterator>::iterator remove_it;
		for (remove_it = remove_slots.begin(); remove_it != remove_slots.end(); remove_it++)
		{
			Slot slot = **remove_it;
			slot->release_signal_ref(this);
			data->slots.erase(*remove_it);
		}

		data->in_call = false;
		if (data->deleted) delete data;
	}

	CL_Signal_v3_Generic *impl;
};

#endif
