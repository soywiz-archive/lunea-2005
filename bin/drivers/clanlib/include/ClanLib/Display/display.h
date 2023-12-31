/*  $Id: display.h,v 1.44 2004/05/08 10:25:05 mbn Exp $
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

#ifndef header_display
#define header_display

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include <string>
#include "color.h"
#include "gradient.h"
#include "../signals.h"
#include "../Core/Math/rect.h"
#include "../Core/Math/quad.h"
#include "../Core/Math/size.h"
#include "../Core/Math/point.h"
#include "../Core/Math/matrix4x4.h"

class CL_DisplayWindow;
class CL_InputEvent;
class CL_PixelBuffer;
class CL_DisplayMode;

//: Top level display class.
//- !group=Display/Display 2D!
//- !header=display.h!
//- <p>The display class provides a static function interface to
//- CL_DisplayWindow and other clanDisplay classes. It uses a selected
//- display window (by default the first created window) to call the
//- equalent functions in CL_DisplayWindow, CL_GraphicContext and such.</p>
//- <p>The entire point of this is to allow applications with only one
//- window to not pass around a pointer to the display window.</p>
class CL_Display
{
//! Attributes:
public:
	//: Returns the currently selected window.
	static CL_DisplayWindow *get_current_window();

	//: Returns the current width of the window.
	static int get_width();

	//: Returns the current height of the window.
	static int get_height();

	//: Returns true if window is currently running fullscreen.
	static bool is_fullscreen();

	//: Returns true if window has focus.
	static bool has_focus();

	//: Returns the pixel buffer for the specified flipping buffer.
	static CL_PixelBuffer *get_buffer(int i);

	//: Returns the amount of flipping buffers being used.
	static int get_buffer_count();

	//: Returns the current flipping buffer being used as the front buffer.
	static CL_PixelBuffer &get_front_buffer();

	//: Returns the current flipping buffer being used as the back buffer.
	static CL_PixelBuffer &get_back_buffer();

	//: Returns the current clipping rectangle used on the graphic context.
	static const CL_Rect &get_cliprect();

	//: Returns the current effective modelview.
	static const CL_Matrix4x4 &get_modelview();
	
//! Operations:
public:
	//: Sets the currently selected window.
	static void set_current_window(CL_DisplayWindow *window);

	//: Change window to running fullscreen mode.
	static void set_fullscreen(int width, int height, int bpp);

	//: Change window to running fullscreen mode.
	static void set_fullscreen(const CL_DisplayMode &display_mode);

	//: Change window to running windowed mode.
	static void set_windowed();

	//: Change window title.
	static void set_title(const std::string &title);

	//: Set window position and size.
	static void set_position(const CL_Rect &pos);

	static void set_position(int x, int y);

	//: Resize window.
	static void set_size(int width, int height);

	//: Changes the amount of surface buffers used in the flipping system.
	//: (2 = double buffer, 3 = triple buffer)
	static void set_buffer_count(int flipping_buffers);

	//: Copy the specified rectangle area from back buffer to front buffer.
	static void update(const CL_Rect &rect);

	//: Flip back buffer to front, making changes visible on screen.
	//param interval: Specifies the minimum number of video frames that are displayed before a buffer swap will occur.
	//- <p>The parameter interval specifies the minimum number of video frames
	//- that are displayed before a buffer swap will occur.</p>
	//- <p>A video frame period is the time required by the monitor to display a 
	//- full frame of video data.  In the case of an interlaced monitor,
	//- this is typically the time required to display both the even and odd 
	//- fields of a frame of video data.  An interval set to a value of 2
	//- means that the color buffers will be swapped at most every other video
	//- frame.</p>
	//- <p>If interval is set to a value of 0, buffer swaps are not synchronized
	//- to a video frame.  The interval value is silently clamped to
	//- the maximum implementation-dependent value supported before being
	//- stored.</p>
	//- <p>If interval is set to a value of -1 (the default), then it will use
	//- the buffer swap used for previous flip. If its the first flip, it will
	//- use the system default, which per default is 1.</p>
	static void flip(int interval = -1);

	//: Flushes current rendering batch.
	//- <p>With the OpenGL target, this causes the graphic context to end its current
	//- active glBegin()/glEnd() pair, making it possible to call other OpenGL calls.</p>
	static void flush();

	//: Draw a pixel at (x, y) using the specified color.
	static void draw_pixel(int x, int y, const CL_Color &color);

	//: Draw a line from (x1, y1) to (x2, y2) using the specified color.
	static void draw_line(int x1, int y1, int x2, int y2, const CL_Color &color);

	//: Draw a rectangle using the specified color.
	static void draw_rect(const CL_Rect &rect, const CL_Color &color);

	//: Draw a gradient rectangle using the specified gradient.
	static void fill_rect(const CL_Rect &rect, const CL_Gradient &gradient);

	//: Draw a filled rectangle using the specified color.
	static void fill_rect(const CL_Rect &rect, const CL_Color &color);
	
	//: Draw a quad using the specified color.
	static void draw_quad(const CL_Quad &quad, const CL_Color &color);

	//: Draw a gradient quad using the specified gradient.
	static void fill_quad(const CL_Quad &quad, const CL_Gradient &gradient);

	//: Draw a filled quad using the specified color.
	static void fill_quad(const CL_Quad &quad, const CL_Color &color);

	//: Clears the whole window using the specified color.
	static void clear(const CL_Color &color = CL_Color(0,0,0));

	//: Set the current clipping rectangle.
	static void set_cliprect(const CL_Rect &rect);

	//: Push current clipping rectangle to stack.
	//- <p>If a rectangle is passed, it afterwards sets clipping
	//- rectangle to the union of the current rectangle and the passed
	//- rectangle.</p>
	static void push_cliprect(const CL_Rect &rect);

	static void push_cliprect();

	//: Pop current clipping rectangle from the stack.
	static void pop_cliprect();

	//: Sets the model view matrix to a new matrix.
	static void set_modelview(const CL_Matrix4x4 &matrix);

	//: Multiplies the passed matrix onto the model view matrix.
	static void add_modelview(const CL_Matrix4x4 &matrix);

	//: Pushes current model view matrix onto the model view stack.
	static void push_modelview();

	//: Sets a translate offset matrix, ignoring any earlier modelview settings.
	//- <p> This offset will affect any subsequent display operations on the current
	//- displaycard, by translating the position of the display operation with the offset.</p>
	static void set_translate(double x, double y, double z = 0.0);

	//: Adds the translate offset.
	//- <p> This offset will affect any subsequent display operations on the current
	//- displaycard, by translating the position of the display operation with the offset.
	//- The offset will be offset by any previous offsets pushed onto the stack,
	//- eg. it inherits the previous offset. </p>
	static void add_translate(double x, double y, double z = 0.0);
	
	//: Push translation offset onto model view stack.
	//- <p>This function is a convenience function for calling push_modelview, then add_translate.</p>
	//- <p> This offset will affect any subsequent display operations on the current
	//- displaycard, by translating the position of the display operation with the offset.
	//- The offset will be offset by any previous offsets pushed onto the stack,
	//- eg. it inherits the previous offset. </p>
	static void push_translate(double x, double y, double z = 0.0);

	//: Sets a rotation matrix, ignoring any earlier model view settings.
	static void set_rotate(double angle, double x = 0.0, double y = 0.0, double z = 1.0);

	//: Adds a rotation matrix to existing model view.
	static void add_rotate(double angle, double x = 0.0, double y = 0.0, double z = 1.0);

	//: Pushes a rotation matrix onto model view stack.
	static void push_rotate(double angle, double x = 0.0, double y = 0.0, double z = 1.0);

	//: Sets a scale matrix, ignoring any earlier model view settings.
	static void set_scale(double x, double y, double z = 1.0);

	//: Adds a scale matrix to existing model view.
	static void add_scale(double x, double y, double z = 1.0);

	//: Pushes a scale matrix onto model view stack.
	static void push_scale(double x, double y, double z = 1.0);

	//: Pops last pushed model view matrix off the stack and makes it the active one.
	static void pop_modelview();

//! Signals:
public:
	//: Signal emitted when window is resized.
	static CL_Signal_v2<int, int> &sig_resize();

	//: Signal emitted when an area of the window is invalidated.
	static CL_Signal_v1<const CL_Rect &> &sig_paint();

	//: Signal emitted when window lost focus.
	static CL_Signal_v0 &sig_lost_focus();

	//: Signal emitted when window gain focus.
	static CL_Signal_v0 &sig_got_focus();

	//: Signal emitted when window is closed.
	static CL_Signal_v0 &sig_window_close();
};

#endif
