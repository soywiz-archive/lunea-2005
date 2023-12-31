/*  $Id: setupsdl.h,v 1.4 2004/03/13 23:04:12 mbn Exp $
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

//! clanSDL="System"
//! header=sdl.h

#ifndef header_setupsdl
#define header_setupsdl

#if _MSC_VER > 1000
#pragma once
#endif

//: ClanSDL initialization functions.
//- !group=SDL/System!
//- !header=sdl.h!
class CL_SetupSDL
{
//! Construction:
public:
	//: Initializes clanSDL.
	//- <p>Constructing a CL_SetupSDL object is equalent to calling CL_SetupSDL::init().</p>
	//- <p>When the CL_SetupSDL instance is destroyed, CL_SetupSDL::deinit() is called.</p>
	CL_SetupSDL(bool register_resources_only = false);

	~CL_SetupSDL();

//! Operations:
public:
	//: Initialize the clanSDL library.
	static void init(bool register_resources_only = false);
	
	//: Deinitialize the clanSDL library.
	static void deinit();
};

#endif
