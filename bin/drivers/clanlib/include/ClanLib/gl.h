/*  $Id: gl.h,v 1.19 2003/12/27 17:14:16 mbn Exp $
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

//: <p>ClanLib OpenGL support. Contains OpenGL binding code and 3D helper
//: frameworks.</p>
//! Global=GL

#ifndef header_gl
#define header_gl

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
	#pragma warning (disable:4786)
#endif

#ifdef WIN32
	#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>

#include "GL/setupgl.h"
#include "GL/opengl.h"
#include "GL/opengl_window.h"
#include "GL/opengl_window_description.h"
#include "GL/opengl_surface.h"
#include "GL/opengl_state.h"
#include "GL/opengl_state_data.h"
#include "GL/viewpoint.h"
#include "GL/light_source.h"
                
#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanGL.lib")
#else
#pragma comment(lib, "clanGLd.lib")
#endif
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "GLU32.lib")
#endif

#endif
