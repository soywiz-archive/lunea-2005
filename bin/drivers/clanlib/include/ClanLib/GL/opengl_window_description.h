/*  $Id: opengl_window_description.h,v 1.8 2004/01/12 13:31:29 mbn Exp $
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

#ifndef header_opengl_window_description
#define header_opengl_window_description

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Display/display_window_description.h"

class CL_OpenGLWindowDescription_Generic;

//: OpenGL specific display window description.
//- !group=GL/Display 2D!
//- !header=gl.h!
//- <p>Use this class to setup OpenGL specific settings for a top level
//- window:</p>
//- <pre>
//- CL_OpenGLWindowDescription desc;
//- dest.set_title("OpenGL window with stereo visual");
//- desc.set_stereo(true);
//- desc.set_stencil_size(4);
//- CL_DisplayWindow window(desc);
//- </pre>
class CL_OpenGLWindowDescription : public CL_DisplayWindowDescription
{
//! Construction:
public:
	//: Constructs a window description with default values.
	CL_OpenGLWindowDescription();

	virtual ~CL_OpenGLWindowDescription();

//! Attributes:
public:
	//: Returns true if only TrueColor and DirectColor visuals are considered.
	//- <p>If not enabled, only PseudoColor and StaticColor visuals are considered.</p>
	bool get_rgba() const;

	//: Returns true if only double-buffered visuals are considered.
	//- <p>If not enabled, only single-buffered visuals are considered.</p>
	bool get_doublebuffer() const;

	//: Returns true if only stereo visuals are considered.
	//- <p>If not enabled, only monoscopic visuals are considered.</p>
	bool get_stereo() const;

	//: Returns the desired color index buffer size.
	//- <p>Ignored in GLX (X11) if the RGBA flag is set.</p>
	//- <p>In WGL (Windows) it specifies the size of the color buffer, excluding the alpha bitplanes.</p>
	int get_buffer_size() const;

	//: Returns the required buffer level.
	//- <p>Buffer level zero corresponds to the main frame buffer of the display. Buffer
	//- level one is the first overlay frame buffer, level two the second overlay frame
	//- buffer, and so on. Negative buffer levels correspond to underlay frame buffers.</p>
	int get_level() const;

	//: Returns the desired number of auxilary buffers.
	int get_aux_buffers() const;

	//: Returns the minimum required red buffer.
	int get_red_size() const;

	//: Returns the minimum required green buffer.
	int get_green_size() const;

	//: Returns the minimum required blue buffer.
	int get_blue_size() const;

	//: Returns the minimum required alpha buffer.
	int get_alpha_size() const;

	//: Returns the minimum required depth buffer.
	int get_depth_size() const;

	//: Returns the minimum required stencil buffer.
	int get_stencil_size() const;

	//: Returns the minimum required red accumulation buffer.
	int get_accum_red_size() const;

	//: Returns the minimum required green accumulation buffer.
	int get_accum_green_size() const;

	//: Returns the minimum required blue accumulation buffer.
	int get_accum_blue_size() const;

	//: Returns the minimum required alpha accumulation buffer.
	int get_accum_alpha_size() const;

//! Operations:
public:
	//: Sets if only TrueColor and DirectColor visuals are considered.
	//- <p>If not enabled, only PseudoColor and StaticColor visuals are considered.</p>
	void set_rgba(bool value);

	//: Sets if only double-buffered visuals are considered.
	//- <p>If not enabled, only single-buffered visuals are considered.</p>
	void set_doublebuffer(bool value);

	//: Sets if only stereo visuals are to be considered.
	//- <p>If not enabled, only monoscopic visuals are considered.</p>
	void set_stereo(bool value);

	//: Sets the desired color index buffer size.
	//- <p>Ignored in GLX (X11) if the RGBA flag is set.</p>
	//- <p>In WGL (Windows) it specifies the size of the color buffer, excluding the alpha bitplanes.</p>
	void set_buffer_size(int value);

	//: Sets the required buffer level.
	//- <p>Buffer level zero corresponds to the main frame buffer of the display. Buffer
	//- level one is the first overlay frame buffer, level two the second overlay frame
	//- buffer, and so on. Negative buffer levels correspond to underlay frame buffers.</p>
	void set_level(int value);

	//: Sets the desired number of auxilary buffers.
	//- <p>Visuals with the smallest number of auxiliary buffers that meets or exceeds
	//- the specified number are preferred.</p>
	void set_aux_buffers(int value);

	//: Sets the minimum required red buffer.
	//- <p>If this value is zero, the smallest available red buffer is preferred. Otherwise,
	//- the largest available red buffer of at least the minimum size is preferred.</p>
	void set_red_size(int value);

	//: Sets the minimum required green buffer.
	//- <p>If this value is zero, the smallest available green buffer is preferred. Otherwise,
	//- the largest available green buffer of at least the minimum size is preferred.</p>
	void set_green_size(int value);

	//: Sets the minimum required blue buffer.
	//- <p>If this value is zero, the smallest available blue buffer is preferred. Otherwise,
	//- the largest available blue buffer of at least the minimum size is preferred.</p>
	void set_blue_size(int value);

	//: Sets the minimum required alpha buffer.
	//- <p>If this value is zero, the smallest available alpha buffer is preferred. Otherwise,
	//- the largest available alpha buffer of at least the minimum size is preferred.</p>
	void set_alpha_size(int value);

	//: Sets the minimum required depth buffer.
	//- <p>If this value is zero, the smallest available depth buffer is preferred. Otherwise,
	//- the largest available depth buffer of at least the minimum size is preferred.</p>
	void set_depth_size(int value);

	//: Sets the minimum required stencil buffer.
	//- <p>If this value is zero, the smallest available stencil buffer is preferred. Otherwise,
	//- the largest available stencil buffer of at least the minimum size is preferred.</p>
	void set_stencil_size(int value);

	//: Sets the minimum required red accumulation buffer.
	//- <p>If this value is zero, the smallest available red accumulation buffer is preferred. Otherwise,
	//- the largest available red accumulation buffer of at least the minimum size is preferred.</p>
	void set_accum_red_size(int value);

	//: Sets the minimum required green accumulation buffer.
	//- <p>If this value is zero, the smallest available green accumulation buffer is preferred. Otherwise,
	//- the largest available green accumulation buffer of at least the minimum size is preferred.</p>
	void set_accum_green_size(int value);

	//: Sets the minimum required blue accumulation buffer.
	//- <p>If this value is zero, the smallest available blue accumulation buffer is preferred. Otherwise,
	//- the largest available blue accumulation buffer of at least the minimum size is preferred.</p>
	void set_accum_blue_size(int value);

	//: Sets the minimum required alpha accumulation buffer.
	//- <p>If this value is zero, the smallest available alpha accumulation buffer is preferred. Otherwise,
	//- the largest available alpha accumulation buffer of at least the minimum size is preferred.</p>
	void set_accum_alpha_size(int value);

//! Implementation:
private:
};

#endif
