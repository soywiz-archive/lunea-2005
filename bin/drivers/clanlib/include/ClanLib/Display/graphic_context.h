/*  $Id: graphic_context.h,v 1.40 2004/04/20 13:36:26 sphair Exp $
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

//! clanDisplay="Display 2D"
//! header=display.h

#ifndef header_graphic_context
#define header_graphic_context

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include "../signals.h"
#include <stack>
#include "color.h"
#include "gradient.h"
#include "stencil_func.h"
#include "../Core/Math/point.h"
#include "../Core/Math/rect.h"
#include "../Core/Math/quad.h"
#include "../Core/Math/matrix4x4.h"

class CL_GraphicContext_Generic;

//: Graphic rendering target.
//- !group=Display/Display 2D!
//- !header=display.h!
//- <p>A graphic context is something that ClanLib can render onto.</p>
class CL_GraphicContext
{
//! Construction:
public:
	//: Constructs a graphic context.
	CL_GraphicContext();

	CL_GraphicContext(const CL_GraphicContext &copy);

	virtual ~CL_GraphicContext();

//! Attributes:
public:
	//: Returns the current width of the context.
	int get_width() const;

	//: Returns the current height of the context.
	int get_height() const;

	//: Returns the current clipping rectangle used on the graphic context.
	const CL_Rect &get_cliprect() const;

	//: Returns the current effective modelview matrix.
	const CL_Matrix4x4 &get_modelview() const;

	//: Returns a pixel value at specified coordinates.
	CL_Color get_pixel(int x, int y) const;

	//: Returns the maximum size of a surface this graphic context supports.
	//- <p>It returns CL_Size(0,0) if there is no limitation to the max
	//- surface size. Of course it is still limited by available memory,
	//- which is not considered by this function.</p>
	CL_Size get_max_surface_size() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_GraphicContext &operator =(const CL_GraphicContext &copy);

	//: Flushes current rendering batch. <i>Deprecated</i>
	//- <p>With the OpenGL target, this causes the graphic context to end its current
	//- active glBegin()/glEnd() pair, making it possible to call other OpenGL calls.</p>
	//- <p><i>This function is deprecated</i></p>.
	void flush();

	//: Draw a pixel at (x, y) using the specified color.
	void draw_pixel(int x, int y, const CL_Color &color);

	//: Draw a line from (x1, y1) to (x2, y2) using the specified color.
	void draw_line(int x1, int y1, int x2, int y2, const CL_Color &color);

	//: Draw a rectangle using the specified color.
	void draw_rect(const CL_Rect &rect, const CL_Color &color);

	//: Draw a gradient rectangle using the specified gradient.
	void fill_rect(const CL_Rect &rect, const CL_Gradient &gradient);

	//: Draw a filled rectangle using the specified color.
	void fill_rect(const CL_Rect &rect, const CL_Color &color);
	
	//: Draw a quad using the specified color.
	void draw_quad(const CL_Quad &quad, const CL_Color &color);

	//: Draw a gradient quad using the specified gradient.
	void fill_quad(const CL_Quad &quad, const CL_Gradient &gradient);

	//: Draw a filled quad using the specified color.
	void fill_quad(const CL_Quad &quad, const CL_Color &color);

	//: Clears the whole context using the specified color.
	void clear(const CL_Color &color = CL_Color(0,0,0));

	//: Set the current clipping rectangle.
	void set_cliprect(const CL_Rect &rect);

	//: Push current clipping rectangle to stack.
	//- <p>If a rectangle is passed, it afterwards sets clipping
	//- rectangle to the union of the current rectangle and the passed
	//- rectangle.</p>
	void push_cliprect(const CL_Rect &rect);

	void push_cliprect();

	//: Pop current clipping rectangle from the stack.
	void pop_cliprect();

	//: Sets the model view matrix to a new matrix.
	void set_modelview(const CL_Matrix4x4 &matrix);

	//: Multiplies the passed matrix onto the model view matrix.
	void add_modelview(const CL_Matrix4x4 &matrix);

	//: Pushes current model view matrix onto the model view stack.
	void push_modelview();

	//: Sets a translate offset matrix, ignoring any earlier model view settings.
	//- <p> This offset will affect any subsequent display operations on the current
	//- displaycard, by translating the position of the display operation with the offset.</p>
	void set_translate(double x, double y, double z = 0.0);

	//: Adds the translate offset.
	//- <p> This offset will affect any subsequent display operations on the current
	//- displaycard, by translating the position of the display operation with the offset.
	//- The offset will be offset by any previous offsets pushed onto the stack,
	//- eg. it inherits the previous offset. </p>
	void add_translate(double x, double y, double z = 0.0);
	
	//: Push translation offset onto model view stack.
	//- <p>This function is a convenience function for calling push_modelview, then add_translate.</p>
	//- <p> This offset will affect any subsequent display operations on the current
	//- displaycard, by translating the position of the display operation with the offset.
	//- The offset will be offset by any previous offsets pushed onto the stack,
	//- eg. it inherits the previous offset. </p>
	void push_translate(double x, double y, double z = 0.0);

	//: Sets a rotation matrix, ignoring any earlier model view settings.
	void set_rotate(double angle, double x = 0.0, double y = 0.0, double z = 1.0);

	//: Adds a rotation matrix to existing model view.
	void add_rotate(double angle, double x = 0.0, double y = 0.0, double z = 1.0);

	//: Pushes a rotation matrix onto model view stack.
	void push_rotate(double angle, double x = 0.0, double y = 0.0, double z = 1.0);

	//: Sets a scale matrix, ignoring any earlier model view settings.
	void set_scale(double x, double y, double z = 1.0);

	//: Adds a scale matrix to existing model view.
	void add_scale(double x, double y, double z = 1.0);

	//: Pushes a scale matrix onto model view stack.
	void push_scale(double x, double y, double z = 1.0);

	//: Pops last pushed model view matrix off the stack and makes it the active one.
	void pop_modelview();

	//: Clear the stencil buffer
	//param int value : value to clear to. Default: 0
	void clear_stencil(int value=0);

	//: Set stencil test function when writing to stencil, and operations to do when a test passes or fails
	//param CL_StencilOp pass : Modification to stencil buffer when a test passes.
	//param CL_StencilOp fail : Modification to stencil buffer when a test fails.
	//param CL_StencilFunc func : Type of test to do when writing to stencil.
	//param int ref : value compared to stencil contents. Default: 1
	void set_stencil_operation(CL_StencilOp pass, CL_StencilOp fail, CL_StencilFunc func, int ref=1);

	//: Enables writing to the stencil buffer 
	//param bool enabled : Enables/disables stencil testing.
	//param bool visible : Enables/disables color buffer writing if stencil writing is enabled. Default: true.
	//param float alpha_limit : Only pixels with alpha >= alpha limit are drawn to the stencil buffer. Default: 0.1f
	void enable_stencil_write(bool enabled, bool visible=true, float alpha_limit=0.1f);

	//: Enables stencil buffer testing
	//- <p> Individual pixels are tested against the values in the stencil buffer, and
	//- drawn depending on the comparison result. This can be used for masking and
	//- boolean operations on bitmaps </p>
	//param bool enabled : Enables/disables stencil testing.
	//param int func : Type of comparison. Default: lequal (pass if ref <= stencil)
	//param int ref : Reference value that the stencil is compared with. Default: 1
	void enable_stencil_test(bool enabled, CL_StencilFunc func=stencil_lequal, int ref=1);

//! Implementation:
public:
	CL_GraphicContext(CL_GraphicContext_Generic *impl);
	
	CL_GraphicContext_Generic *impl;
};

#endif
