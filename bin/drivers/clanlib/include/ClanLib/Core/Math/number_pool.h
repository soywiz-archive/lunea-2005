/*
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

//! clanCore="Math"
//! header=core.h

#ifndef header_number_pool
#define header_number_pool

#if _MSC_VER > 1000
#pragma once
#endif

#include <climits>
#include <set>

//: A number generator pool.
//- !group=Core/Math!
//- !header=core.h!
//- <p>It generates unique numbers from a pool of ushort16.</p>
class CL_NumberPool
{
//! Construction:
public:
	//: Constructs a number pool.
	CL_NumberPool();

//! Operations:
public:
	//: Return a unique number.
	unsigned short get_number();

	//: Pass a number back in so as to beable to reuse the unique number.
	//- <p>NOTE: numbers that were not given before or already returned back will be discarded.</p>
	void return_number(unsigned short number);

//! Implementation:
private:
	//: A pool of available unique number.
	std::set<unsigned short> available_numbers;

	//: The initial number range.
	unsigned short initial_number_range;

};

#endif
