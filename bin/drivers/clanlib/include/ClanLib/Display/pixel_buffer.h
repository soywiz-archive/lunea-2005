/*  $Id: pixel_buffer.h,v 1.41 2004/05/06 21:14:00 grumbel Exp $
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

#ifndef header_pixel_buffer
#define header_pixel_buffer

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/Math/rect.h"

class CL_PixelFormat;
class CL_Palette;
class CL_PixelBuffer_Generic;
class CL_GraphicContext;
class CL_Color;

//: Pixel data access.
//- !group=Display/Display 2D!
//- !header=display.h!
class CL_PixelBuffer
{
//! Construction:
public:
	//: Constructs a pixel buffer.
	//param width: Width of pixel buffer, in pixels.
	//param height: Height of pixel buffer, in pixels.
	//param pitch: Bytes per line in pixel buffer.
	//param format: Pixel format of pixel buffer.
	//param palette: Palette used in pixel buffer.
	//param data: Data pointer to pixel data. If null, will construct a memory pixel buffer with the given dimensions.
	//- <p>If the data pointer is not null, it will internally just point at the memory location specified by data.
	//- In other words, CL_PixelBuffer do not copy the data, and it does not delete the data pointer when destroyed itself.</p>
	CL_PixelBuffer(int width, int height, int pitch, const CL_PixelFormat &format, void *data = 0);

	CL_PixelBuffer(int width, int height, int pitch, const CL_PixelFormat &format, const CL_Palette &palette, void *data = 0);

	CL_PixelBuffer(const CL_PixelBuffer &copy);

	CL_PixelBuffer();

	virtual ~CL_PixelBuffer();

//! Attributes:
public:
	//: Returns the pixel format of the pixel buffer.
	const CL_PixelFormat &get_format() const;

	//: Returns the palette of the pixel buffer.
	const CL_Palette &get_palette() const;

	//: Returns the buffer width.
	int get_width() const;

	//: Returns the buffer height.
	int get_height() const;

	//: Returns the pitch (bytes per scanline).
	unsigned int get_pitch() const;

	//: Returns a pointer to the beginning of the pixel buffer. Pointer
	//: is only valid inside a lock/unlock session.
	void *get_data();
	
	//: Returns the pixel at coordinates x and y.
	//: Only valid within a lock/unlock session.
	CL_Color get_pixel(int x, int y);

//! Operations:
public:
	//: Copy assignment operator.
	CL_PixelBuffer &operator =(const CL_PixelBuffer &copy);

	//: Return true if the CL_PixelBuffer is valid and useable
	operator bool () const;

	//: Locks the pixel buffer, making calls to get_data() valid.
	void lock();

	//: Unlocks the pixelbuffer.
	void unlock();

	//: Convert pixel buffer to the pixel format of the target buffer, storing
	//: the result in the target buffer.
	//param target: Target pixel buffer.
	//param buffer: Buffer getting stored pixels in the specified format and pitch.
	//param format: Pixel format of target buffer.
	//param dest_pitch: Bytes per line of target buffer.
	//param dest_rect: Destination rectangle for conversion.
	//param src_rect: Source rectangle for conversion.
	void convert(CL_PixelBuffer *target);

	void convert(void *buffer, const CL_PixelFormat &format, int dest_pitch, const CL_Rect &dest_rect, const CL_Rect &src_rect=CL_Rect(0,0,0,0));

	//: Convert one line of pixel data to target buffer.
	//param buffer: Buffer getting stored pixels in the specified format
	//param format: Pixel format of target buffer.
	//param y: Specifies which line to convert when converting one single line.
	void convert_line(void *buffer, const CL_PixelFormat &format, int y);

	//: Converts current buffer to a new pixel format and returns the result.
	CL_PixelBuffer to_format(const CL_PixelFormat &format);

	//: Sets a new colorkey without converting the buffer.
	//param enabled: Enable or disable the colorkey.
	//param colorkey: New colorkey to use.
	void set_colorkey(bool enabled, unsigned int colorkey);
	
	//: Draw a pixel at (x, y) using the specified color.
	//: Only valid within a lock/unlock session.
	void draw_pixel(int x, int y, const CL_Color &color);

//! Implementation:
public:
	CL_PixelBuffer(CL_PixelBuffer_Generic *impl);

protected:
	//: Pixel data implementation.
	CL_PixelBuffer_Generic *impl;
};

#endif
