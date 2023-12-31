 /*  $Id: sharedptr.h,v 1.14 2004/04/21 18:42:51 harry Exp $
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

#ifndef clanlib_sharedptr_header
#define clanlib_sharedptr_header

template <typename TEvil>
class CL_SharedPtr_Generic
{
public:
	CL_SharedPtr_Generic() : ptr(0), ref_count(1) { return; }

	virtual ~CL_SharedPtr_Generic() { return; }

public:
	//: Pointer to new-allocated data, or else 0:
	TEvil *ptr;
	
	//: reference count:
	unsigned int ref_count;
};

template <typename T, typename TEvil>
class CL_SharedPtr_Deleter : public CL_SharedPtr_Generic<T>
{
public:
	CL_SharedPtr_Deleter(TEvil *e) { this->ptr = e; }

	~CL_SharedPtr_Deleter() { delete this->ptr; }
};

//: Shared pointer class (automatically deletes data when all CL_SharedPtrs to data are gone).
//- !group=Core/System!
//- !header=core.h!
//- <p> Use CL_SharedPtr when you have data that's intended to be shared between
//- multiple users without each user needing an individual copy. </p>
//- <p> Note that CL_SharedPtr uses a very simple reference counting system, so is susecptible
//- to circular loop issues. </p>
template <typename T, typename U = T>
class CL_SharedPtr
{
//! Construction:
public:
	//: Constructs a CL_SharedPtr.
	//param t: A pointer which was the return value of a 'new' call.
	//- <p> After the CL_SharedPtr has been constructed based on a passed pointer,
	//- the CL_SharedPtr takes full control over that data. The original pointer shouldn't
	//- be used to access or delete the data anymore; instead, use the CL_SharedPtr. </p>
	CL_SharedPtr() : impl(0) { return; }

	CL_SharedPtr(const CL_SharedPtr<T, U>& other) : impl(other.impl) { increment(); }

	template <typename D>
	explicit CL_SharedPtr(D* ptr) : impl(new CL_SharedPtr_Deleter<T, D>(ptr)) { return; }

	explicit CL_SharedPtr(CL_SharedPtr_Generic<T> *impl) : impl(impl) { increment(); }
	
	~CL_SharedPtr() { decrement(); }
	
//! Attributes:
public:
	//: Returns true if this CL_SharedPtr is not dereferencable.
	bool is_null() const { return impl ? (impl->ptr != 0) : false; }

	//: Returns number of references (including this one) to the data cache.
	//- <p> Returns 0 if this pointer is null. </p>
	int get_ref_count() const { if (impl == 0) return 0; return impl->ref_count; }
	
	//: Gives access to the pointer itself.
	//- <p> Be careful not to keep the returned pointer around after doing any
	//- non-const operations on the CL_LazyCopyPtr; it could be invalid
	//- after that.</p>
	U* get() { return (U*) ((impl != 0) ? impl->ptr : 0); }

	U const* get() const { return (const U*) ((impl != 0) ? impl->ptr : 0); }

	//: Return the pointer.
	operator U*() { return get(); }

	//: Returns the pointer.
	operator U const*() const { return get(); }

	//: Pointer equality check operator.
	//- <p> This will return true if the CL_SharedPtrs point to the same data. It doesn't
	//- check the data itself for equality. </p>
	bool operator==(const T* other) const { return other == ((impl != 0) ? impl->ptr : 0); }

	bool operator==(const CL_SharedPtr<T, U>& other) const { return other.impl == impl; }

//! Operations:
public:
	//: Copy assignment operator.
	//param t: A pointer which was the return value of a 'new' call.
	//- <p> Once the assignment statement is finished when assigning a passed pointer,
	//- the CL_SharedPtr takes full control over that data. The original pointer shouldn't
	//- be used to access or delete the data anymore; instead, use the CL_SharedPtr. </p>
	CL_SharedPtr<T, U>& operator=(const CL_SharedPtr<T, U>& other)
	{
		if (other.impl != impl)
		{
			decrement();
			impl = other.impl;
			increment();
		}
		return *this;
	}

	template <typename D>
	CL_SharedPtr<T, U>& operator=(D* t)
	{
		decrement();
		impl = new CL_SharedPtr_Deleter<T, D>(t);
		return *this;
	}
	
	//: Dereferencing operator.
	U& operator*() { return *((U*) impl->ptr); }

	U const& operator*() const { return *((const U*) impl->ptr); }
	
	//: Indirect member access operator.
	U* operator->() { return (U*) impl->ptr; }

	U const* operator->() const { return (const U*) impl->ptr; }

	CL_SharedPtr_Generic<T> *get_impl() { return impl; }

//! Implementation:
private:
	// Shared data:
	CL_SharedPtr_Generic<T> *impl;
	
	//: Increases the ref count
	void increment()
	{
		if (impl != 0)
			++impl->ref_count;
	}
	
	//: Decreases the ref count, deletes entry and sets ptr to 0 if ptr_ref_count reaches zero
	void decrement()
	{
		if (impl != 0)
		{
			if (--impl->ref_count == 0)
			{
				delete impl;
				impl = 0;
			}
		}
	}
};

#endif
