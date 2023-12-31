/*  $Id: error.h,v 1.14 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_error
#define header_error

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

//: Exception class in ClanLib.
//- !group=Core/System!
//- !header=core.h!
//- <p>If something goes wrong in a clanlib function, it will throw an exception of
//- this class.</p>
class CL_Error
{
public:
//! Construction:
	//: Error Constructor.
	CL_Error(const char *message) { this->message = message; }

	CL_Error(const std::string &message) { this->message = message; }

	//: The error message
	std::string message;
};

//: This function throws an error.
void cl_throw_error(const char *message);
void cl_throw_error(const std::string &message);

#endif
