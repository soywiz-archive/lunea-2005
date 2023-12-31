/*  $Id: opengl_surface.h,v 1.5 2004/02/18 14:32:15 sphair Exp $
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

//! clanGL="Display 2D"
//! header=gl.h

#ifndef header_opengl_surface
#define header_opengl_surface

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Display/surface.h"

//: OpenGL surface.
//- !group=GL/Display 2D!
//- !header=gl.h!
class CL_OpenGLSurface : public CL_Surface
{
//! Construction:
public:
	//: Constructs an opengl surface.
	CL_OpenGLSurface();
	
	CL_OpenGLSurface(const CL_Surface &copy);
	
	CL_OpenGLSurface(
		CL_PixelBuffer *provider,
		bool delete_provider = false,
		int flag = flag_none);

	CL_OpenGLSurface(
		const std::string &resource_id,
		CL_ResourceManager *manager);

	CL_OpenGLSurface(const std::string &filename, int flag = flag_none);

	virtual ~CL_OpenGLSurface();

//! Attributes:
public:

//! Operations:
public:
	//: Bind surface texture in OpenGL.
	void bind();

//! Implementation:
private:
};

#endif
