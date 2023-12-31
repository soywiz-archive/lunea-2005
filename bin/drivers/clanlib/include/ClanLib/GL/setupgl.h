/*  $Id: setupgl.h,v 1.17 2004/03/13 23:04:12 mbn Exp $
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

//! clanGL="System"
//! header=gl.h

#ifndef header_setupgl
#define header_setupgl

#if _MSC_VER > 1000
#pragma once
#endif

//: ClanGL initialization functions.
//- !group=GL/System!
//- !header=gl.h!
class CL_SetupGL
{
//! Construction:
public:
	//: Initializes clanGL.
	//- <p>Constructing a CL_SetupGL object is equalent to calling CL_SetupGL::init().</p>
	//- <p>When the CL_SetupGL instance is destroyed, CL_SetupGL::deinit() is called.</p>
	CL_SetupGL(bool register_resources_only = false);

	~CL_SetupGL();

//! Operations:
public:
	//: Initialize the clanGL library.
	static void init(bool register_resources_only = false);
	
	//: Deinitialize the clanGL library.
	static void deinit();
};

#endif
