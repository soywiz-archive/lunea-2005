/*  $Id: opengl.h,v 1.26 2004/04/20 19:40:52 sphair Exp $
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

#ifndef header_opengl
#define header_opengl

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>
#include <utility>
#include "../Display/pixel_format.h"

class CL_GLFunctions;

//: Extension procedure address typedef for OpenGL.
typedef void (CL_ProcAddress)();

typedef unsigned int CLenum;
typedef unsigned char CLboolean;
typedef unsigned int CLbitfield;
typedef signed char CLbyte;
typedef short CLshort;
typedef int CLint;
typedef int CLsizei;
typedef unsigned char CLubyte;
typedef unsigned short CLushort;
typedef unsigned int CLuint;
typedef float CLfloat;
typedef float CLclampf;
typedef double CLdouble;
typedef double CLclampd;
typedef void CLvoid;

//: OpenGL utility class.
//- !group=GL/System!
//- !header=gl.h!
class CL_OpenGL
{
//! Attributes:
public:
	//: Get OpenGL extension specific function address.
	static CL_ProcAddress *get_proc_address(const std::string &function_name);

	//: Function table for OpenGL 1.5:
	static CL_GLFunctions *functions;

	//: Get a pixel format out of an OpenGL format.
	//- <p>The function returns false if it can't convert format, otherwise the
	//- the formatare returned with values in pf.</p>
	static bool from_opengl_pixelformat(CLenum format, CLenum type, CL_PixelFormat &pf);

	//: Get a OpenGL format out of a pixel format.
	//- <p>The function returns false if pixelformat color depth is not convertible to 
	//- OpenGL pixel format, otherwise the format and type are returned with values in format and type.</p>
	static bool to_opengl_pixelformat(const CL_PixelFormat &pf, CLenum &format, CLenum &type);
};

#endif
