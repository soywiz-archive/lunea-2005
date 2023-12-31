/*  $Id: opengl_window.h,v 1.15 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_opengl_window
#define header_opengl_window

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Display/display_window.h"

#ifdef WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#endif

//: OpenGL top level window.
//- !group=GL/Display 2D!
//- !header=gl.h!
class CL_OpenGLWindow : public CL_DisplayWindow
{
//! Construction:
public:
	//: Constructs an opengl window.
	//param title: Titlebar text.
	//param width, height: Size of window, in pixels.
	//param start_fullscreen: If true, window will go full screen.
	//param allow_resize: If true, window will have resize grabbers.
	//param flipping_buffer: Amount of buffers in flipping system.
	CL_OpenGLWindow();

	CL_OpenGLWindow(const CL_OpenGLWindow &copy);

	CL_OpenGLWindow(
		const std::string &title,
		int width,
		int height,
		bool start_fullscreen = false,
		bool allow_resize = false,
		int flipping_buffers = 2);

	~CL_OpenGLWindow();

//! Attributes:
public:
#ifdef WIN32
	//: Returns the Win32 OpenGL resource context.
	HGLRC get_context();

	//: Returns the Win32 device context handle.
	HDC get_dc();

	//: Returns the Win32 window handle.
	HWND get_wnd();
#else
	//: Retuens the X11 display handle.
	Display *get_wnd();
#endif

//! Operations:
public:

//! Implementation:
private:
};

#endif
