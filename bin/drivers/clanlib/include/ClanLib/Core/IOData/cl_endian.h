/*  $Id: cl_endian.h,v 1.14 2004/01/02 15:42:43 mbn Exp $
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

//! clanCore="I/O Data"
//! header=core.h

#ifndef header_endian
#define header_endian

#if _MSC_VER > 1000
#pragma once
#endif

//: Endianess management class.
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>The CL_Endian class is used to convert between different endianess. There
//- are also a set of defines to the lazy developer:</p>
//- <p>#define SWAP_IF_BIG(i)<br>
//- #define SWAP_IF_LITTLE(i)<br>
//- #define SWAP_IF_BIG_ALOT(i, times)<br>
//- #define SWAP_IF_LITTLE_ALOT(i, times)<br>
//- #define IS_SYSTEM_64BIT()</p>
//- <p>Each of these defines call CL_Endian::is_system_big() and CL_Endian::swap.</p>
class CL_Endian
{
public:
//! Operations:
	//: Swaps larger amounts of data between little and big endian.
	//param data: Data to be swapped.
	//param type_size: Size of datatype to be swapped.
	//param total_times: Number of 'type_size' size data chunks to be swapped.
	static void swap(void *data, int type_size, int total_times=1);

//! Attributes:
	//: Returns true if big endian system.
	//return: True if big endian system, false otherwise.
	static bool is_system_big();

	//: Returns true if 64 bit system.
	//return: True if 64 bit, false otherwise.
	static bool is_system_64bit();
};

// Defines to the lazy developer:
#define SWAP_IF_BIG(i) if (CL_Endian::is_system_big()) CL_Endian::swap(&i, sizeof(i));
#define SWAP_IF_LITTLE(i) if (!CL_Endian::is_system_big()) CL_Endian::swap(&i, sizeof(i));

#define SWAP_IF_BIG_ALOT(i, times) if (CL_Endian::is_system_big()) CL_Endian::swap(&i, sizeof(i), times);
#define SWAP_IF_LITTLE_ALOT(i, times) if (!CL_Endian::is_system_big()) CL_Endian::swap(&i, sizeof(i), times);

#define IS_SYSTEM_64BIT() CL_Endian::is_system_64bit();

#endif
