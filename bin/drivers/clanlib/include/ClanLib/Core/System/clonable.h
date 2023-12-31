 /*  $Id: clonable.h,v 1.4 2004/03/08 15:37:12 sphair Exp $
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

#ifndef clanlib_clonable_header
#define clanlib_clonable_header

//: Clonable interface.
//- !group=Core/System!
//- !header=core.h!
class CL_Clonable
{
//! Construction:
public:
	virtual ~CL_Clonable() {}

	virtual CL_Clonable* clone() const =0;

//! Attributes:
public:
	//: Dummy method; templates that require clonable can use this to check
	void must_be_derived_from_cl_clonable() const {}
};

#endif
