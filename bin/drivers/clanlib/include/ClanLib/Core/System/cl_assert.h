/*  $Id: cl_assert.h,v 1.20 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_cl_assert
#define header_cl_assert

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef __PRETTY_FUNCTION__ 
#define __PRETTY_FUNCTION__ NULL
#endif

#ifndef __STRING
#define cl_assert(a) CL_Assert::die(a, __FILE__, __LINE__, __PRETTY_FUNCTION__, #a);
#else
#define cl_assert(a) CL_Assert::die(a, __FILE__, __LINE__, __PRETTY_FUNCTION__, __STRING(a));
#endif

//: This is ClanLib's assertion class.
//- !group=Core/System!
//- !header=core.h!
class CL_Assert
{
//! Operations:
public:
	//: Produces an assert.
	//- <p>This function shouldn't be called directly -
	//- instead, use the cl_assert macro.
	//-  For example: cl_assert(should_not_be_zero != 0)</p>
	//param a: Asserts if false.
	//param file: Name of the file where the assert occurred.
	//param line: Line in the file where the assert occurred.
	//param func: Function in which the assert occurred.
	//param assert_str: String that describe the assertion check.
	static void die(bool a, const char *file, int line, const char *func, const char *assert_str);
};

#endif
