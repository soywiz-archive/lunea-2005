 /*  $Id: owningptr.h,v 1.4 2004/01/02 15:42:43 mbn Exp $
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

#ifndef clanlib_owningptr_header
#define clanlib_owningptr_header

//: Posessive pointer class (copying the pointer copies what it points to).
//- !group=Core/System!
//- !header=core.h!
//- <p> Use CL_OwningPtr when you require the data to be on the heap, but otherwise
//- want it to have very stack-instace-like semantics for copying, destruction, etc. </p>
template <typename T, typename U = T> class CL_OwningPtr
{
	//! Construction:
	public:
		//: Constructs a CL_OwningPtr.
		//param t: A pointer which was the return value of a 'new' call.
		//- <p> After the CL_OwningPtr has been constructed based on a passed pointer,
		//- the CL_OwningPtr takes full control over that data. The original pointer shouldn't
		//- be used to access or delete the data anymore; instead, use the CL_OwningPtr. </p>
		CL_OwningPtr() : ptr(0) {}
		CL_OwningPtr(const CL_OwningPtr<T, U>& other) : ptr((T*)(other.ptr->clone())) {}
		CL_OwningPtr(T* t) : ptr(t) {}
		
		~CL_OwningPtr() {delete ptr;}
	
	//! Attributes:
	public:		
		//: Returns true if this CL_OwningPtr is not dereferencable.
		bool is_null() const {if (ptr == 0) return true; return false;}
		
		//: Gives access to the pointer itself.
		//- <p> Be careful not to keep the returned pointer around after doing any
		//- non-const operations on the CL_LazyCopyPtr; it could be invalid
		//- after that.</p>
		U* get() {return (U*)ptr;}
		const U* get() const {return (const U*)ptr;}
		
	//! Operations:
	public:	
		//: Copy assignment operator.
		//param t: A pointer which was the return value of a 'new' call.
		//- <p> Once the assignment statement is finished when assigning a passed pointer,
		//- the CL_OwningPtr takes full control over that data. The original pointer shouldn't
		//- be used to access or delete the data anymore; instead, use the CL_OwningPtr. </p>
		CL_OwningPtr<T, U>& operator=(const CL_OwningPtr<T, U>& other)
		{
			if (&other != this)
			{
				T* cpy;
				if (other.ptr != 0)
					cpy = (T*)(other.ptr->clone());
				else
					cpy = 0;
				
				delete ptr;
				ptr = cpy;
			}
			
			return *this;
		}
		CL_OwningPtr<T, U>& operator=(T* t)
		{
			delete ptr;
			ptr = t;
			return *this;
		}
		
		//: Dereferencing operator.
		U& operator*() {return *((U*)ptr);}
		U const& operator*() const {return *((const U*)ptr);}
		
		//: Forces a const dereference.
		//- <p> Like operator*, but forces a const deref even if in non-const context. 
		//- This is intended mostly to make it easy to exchange CL_OwningPtr and CL_LazyCopyPtr. </p>
		U const& cd() const {return *((const U*)ptr);}
		
		//: Indirect member access operator.
		U* operator->() {return (U*)ptr;}
		U const* operator->() const {return (const U*)ptr;}
	
	//! Implementation:
	private:
		//Pointer to new-allocated data, or else 0
		T* ptr;
		
		//Not to be called, this just ensures that T is derived from CL_Clonable
		void dummy() { ptr->must_be_derived_from_cl_clonable(); }
};

#endif
