/*  $Id: lazycopyptr.h,v 1.6 2004/01/27 02:19:27 mbn Exp $
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

#ifndef clanlib_lazycopyptr_header
#define clanlib_lazycopyptr_header

#include "sharedptr.h"

//: Copy-on-write pointer class (acts like CL_OwningPtr, except holds off actual copy until non-const dereference).
//- !group=Core/System!
//- !header=core.h!
//- <p> Use CL_LazyCopyPtr when you want stack-instance-like semantics for your data, but want to avoid
//- doing an actual copy of the data until it's neccessary, if ever. This is often useful for classes
//- containing implementation pointers with mutable data; the class might just be copied and the copy
//- destroyed without any actual change of the copy's data. If that were the case and the class was
//- using CL_LazyCopyPtr for its implementation pointer, an unneccessary copy would've been saved. </p>
//- <p> The way to take advantage of CL_LazyCopyPtr's lazy copying is to prefer const dereferences whenever
//- possible. If the CL_LazyCopyPtr is a member of a class, and the dereference is within a const method
//- of that class, then the const version of operator* or operator-> is automatically used. To dereference
//- the CL_LazyCopyPtr constly when not in a const method of a class owning the CL_LazyCopyPtr, use the cd() method. </p>
template <typename T, typename U = T> class CL_LazyCopyPtr
{
//! Construction:
public:
	//: Constructs a CL_LazyCopyPtr.
	//param t: A pointer which was the return value of a 'new' call.
	//- <p> Once the assignment statement is finished when assigning a passed pointer,
	//- the CL_OwningPtr takes full control over that data. The original pointer shouldn't
	//- be used to access or delete the data anymore; instead, use the CL_OwningPtr. </p>
	CL_LazyCopyPtr() {}
	CL_LazyCopyPtr(T* t) : ptr(t) {}
	
//! Attributes:
public:
	//: Returns true if this CL_LazyCopyPtr is not dereferencable.
	bool is_null() const {return ptr.is_null();}
	
	//: Returns number of references (including this one) to the data cache.
	//- <p> Returns 0 if this pointer is null. </p>
	//- <p> If your code depends on this, it may not be using LazyCopyPtr correctly.
	//- The idea is that the user code shouldn't concern itself with whether or
	//- not a copy has taken place, just trust that LazyCopyPtr will copy it if
	//- neccessary. </p>
	int get_ref_count() const {return ptr.ptr_ref_count();}
	
	//: Gives access to the pointer itself.
	//- <p> Be careful not to keep the returned pointer around after doing any
	//- non-const operations on the CL_LazyCopyPtr; it could be invalid
	//- after that.</p>
	U* get() {return ptr.get();}
	const U* get() const {return ptr.get();}
	
//! Operations:
public:
	//: Copy assignment operator.
	//param t: A pointer which was the return value of a 'new' call.
	//- <p> Once the assignment statement is finished when assigning a passed pointer,
	//- the CL_LazyCopyPtr takes full control over that data. The original pointer shouldn't
	//- be used to access or delete the data anymore; instead, use the CL_LazyCopyPtr. </p>
	CL_LazyCopyPtr<T, U>& operator=(T* t) {ptr = t; return *this; }
	
	//: Dereferencing operator.
	U& operator*() {uniquify(); return *ptr;}
	U const& operator*() const {return *ptr;}
	
	//: Forces a const dereference.
	//- <p> Like operator*, but forces a const dereference even if in non-const context. </p>
	U const& cd() const {return *ptr;}
	
	//: Indirect member access operator.
	U* operator->() {uniquify(); return ptr.operator->();}
	U const* operator->() const {return ptr.operator->();}

//! Implementation:
private:
	CL_SharedPtr<T, U> ptr;
	
	//: Ensures that we are the only user of this data
	void uniquify() {if (ptr.get_ref_count() > 1) ptr = CL_SharedPtr<T, U>((T*)(ptr->clone()));}
	
	//Not to be called, this just ensures that T is derived from CL_Clonable
	void dummy() {ptr->must_be_derived_from_cl_clonable();}
};

#endif
