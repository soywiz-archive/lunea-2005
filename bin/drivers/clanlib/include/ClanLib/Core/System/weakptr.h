 /*  $Id: weakptr.h,v 1.4 2004/04/20 21:50:23 harry Exp $
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

#ifndef clanlib_weakptr_header
#define clanlib_weakptr_header

#include "sharedptr.h"

//: Weak pointer class (pointer to a CL_SharedPtr object that dont increase reference count).
//- !group=Core/System!
//- !header=core.h!
//- <p>Use CL_WeakPtr when you want to have a pointer that is reference counted by CL_SharedPtr
//- but want a pointer that dont increase the reference count.</p>
//- <p>The purpose of CL_WeakPtr is to avoid circular loop issues. By using CL_WeakPtr you
//- can construct new CL_SharedPtr'ed objects based on the weak pointer.</p>
template <typename T, typename U = T>
class CL_WeakPtr
{
//! Construction:
public:
	CL_WeakPtr() : impl(0) { return; }

	CL_WeakPtr(CL_SharedPtr<T, U> &other) : impl(other.get_impl()) { return; }

//! Operations:
public:
	//: Returns true if this CL_SharedPtr is not dereferencable.
	bool is_null() const { return impl ? (impl->ptr != 0) : 0; }

	//: Returns number of references (including this one) to the data cache.
	//- <p> Returns 0 if this pointer is null. </p>
	int get_ref_count() const { if (impl == 0) return 0; return impl->ref_count; }
	
	//: Gives access to the pointer itself.
	//- <p> Be careful not to keep the returned pointer around after doing any
	//- non-const operations on the CL_LazyCopyPtr; it could be invalid
	//- after that.</p>
	U* get() { return (U*) ((impl != 0) ? impl->ptr : 0); }

	const U* get() const { return (const U*) ((impl != 0) ? impl->ptr : 0); }

	//: Returns the pointer.
	operator const U*() const { return get(); }

	//: Returns the pointer as a shared ptr.
	operator CL_SharedPtr<T, U>() const { return CL_SharedPtr<T, U>(impl); }

	//: Dereferencing operator.
	U& operator*() { return *((U*) impl->ptr); }

	U const& operator*() const { return *((const U*) impl->ptr); }
	
	//: Indirect member access operator.
	U* operator->() { return (U*) impl->ptr; }

	U const* operator->() const { return (const U*) impl->ptr; }

	//: Pointer equality check operator.
	//- <p> This will return true if the CL_SharedPtrs point to the same data. It doesn't
	//- check the data itself for equality. </p>
	bool operator==(const T* other) const { return other == ((impl != 0) ? impl->ptr : 0); }

	bool operator==(const CL_SharedPtr<T, U>& other) const { return other.impl == impl; }

//! Implementation:
private:
	CL_SharedPtr_Generic<T> *impl;
};

#endif
