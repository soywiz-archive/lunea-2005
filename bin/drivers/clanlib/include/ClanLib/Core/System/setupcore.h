/*  $Id: setupcore.h,v 1.21 2004/03/13 23:04:12 mbn Exp $
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

#ifndef header_setupcore
#define header_setupcore

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef WIN32
#include <windows.h>
#endif

//: ClanCore initialization functions.
//- !group=Core/System!
//- !header=core.h!
class CL_SetupCore
{
//! Construction:
public:
	//: Initializes clanCore.
	//- <p>Constructing a CL_SetupCore object is equalent to calling CL_SetupCore::init().</p>
	//- <p>When the CL_SetupCore instance is destroyed, CL_SetupCore::deinit() is called.</p>
	CL_SetupCore(bool register_resources_only = false);

	~CL_SetupCore();

public:
//! Operations:
	//: Initialize clanCore.
	//- <p>If you are using CL_ClanApplication to boot your
	//- application, you do not need to call this function.</p>
	//- <p>If using Win32 (and without CL_ClanApplication) -
	//- You must call CL_SetupCore::set_instance(HINSTANCE hInstance)
	//- before this calling this function</p>
	static void init(bool register_resources_only = false);

	//: Deinitialize clanCore.
	//- <p>If you are using CL_ClanApplication to boot your
	//- application, you do not need to call this function.</p>
	static void deinit();

#ifdef WIN32
	//: Set instance.
	//- <p>If doing win32 initialization without using clanApp, you must call
	//- this function before calling CL_SetupCore::init().</p>
	static void set_instance(HINSTANCE hInstance);
#endif
};

#endif
