/*  $Id: setupmikmod.h,v 1.13 2004/03/13 23:04:12 mbn Exp $
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

//! clanMikMod="System"
//! header=mikmod.h

#ifndef header_setupmikmod
#define header_setupmikmod

#if _MSC_VER > 1000
#pragma once
#endif

//: ClanMikMod initialization.
//- !group=MikMod/System!
//- !header=mikmod.h!
class CL_SetupMikMod
{
//! Construction:
public:
	//: Initializes clanMikMod.
	//- <p>Constructing a CL_SetupMikMod object is equalent to calling CL_SetupMikMod::init().</p>
	//- <p>When the CL_SetupMikMod instance is destroyed, CL_SetupMikMod::deinit() is called.</p>
	CL_SetupMikMod(bool register_resources_only = false);

	~CL_SetupMikMod();

//! Operations:
public:
	//: Call this function in init_modules() to use clanMikMod.
	static void init(bool register_resources_only = false);

	//: Call this function in deinit_modules().
	static void deinit();
};

#endif
