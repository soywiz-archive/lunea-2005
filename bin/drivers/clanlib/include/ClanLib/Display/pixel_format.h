/*  $Id: pixel_format.h,v 1.20 2004/04/04 14:37:12 harry Exp $
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

#ifndef header_pixelformat
#define header_pixelformat

#if _MSC_VER > 1000
#pragma once
#endif

#include "pixel_format_type.h"

//: Pixel data format description.
//- !group=Display/Display 2D!
//- !header=display.h!
class CL_PixelFormat
{
//! Construction:
public:
	//: Constructs a pixel format description.
	//param depth: Bytes per pixel.
	//param red_mask: Red color mask.
	//param green_mask: Green color mask.
	//param blue_mask: Blue color mask.
	//param alpha_mask: Alpha transparency mask.
	//param use_colorkey: True if source color key transparency is used (single color transparency).
	//param colorkey: Source color key (pixel value that means transparent).
	CL_PixelFormat();

	CL_PixelFormat(const CL_PixelFormat &copy);

	CL_PixelFormat(
		int depth,
		unsigned int red_mask,
		unsigned int green_mask,
		unsigned int blue_mask,
		unsigned int alpha_mask = 0,
		bool use_colorkey = false,
		unsigned int colorkey = 0,
		CL_PixelFormatType type = pixelformat_rgba);

//! Attributes:
public:
	//: Returns true if this pixel format is the same as the other one.
	bool operator ==(const CL_PixelFormat &other) const;

	//: Returns true if this pixel format is not the same as the other one.
	bool operator !=(const CL_PixelFormat &other) const;
	
	//: Returns the pixel format type (RGB or Indexed).
	CL_PixelFormatType get_type() const { return type; }

	//: Returns true if format uses a source color key.
	bool has_colorkey() const { return colorkey_enabled; }

	//: Returns the depth of the pixel format.
	int get_depth() const { return depth; }

	//: Returns the source color key.
	unsigned int get_colorkey() const { return colorkey; }

	//: Returns the red component color mask.
	unsigned int get_red_mask() const { return red_mask; }

	//: Returns the green component color mask.
	unsigned int get_green_mask() const { return green_mask; }

	//: Returns the blue component color mask.
	unsigned int get_blue_mask() const { return blue_mask; }

	//: Returns the alpha component color mask.
	unsigned int get_alpha_mask() const { return alpha_mask; }

//! Statics:
public:
	//: Pixel format with 32 bit depth, 8 bits per color mask.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0xff000000</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x00ff0000</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0x0000ff00</td></tr>
	//- <tr><td>alpha mask</td><td>=</td><td>0x000000ff</td></tr>
	//- </table>
	static CL_PixelFormat rgba8888;

	//: Pixel format with 24 bit depth, 8 bits per color mask, no alpha.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0xff0000</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x00ff00</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0x0000ff</td></tr>
	//- </table>
	static CL_PixelFormat rgb888;

	//: Pixel format with 16 bit depth, 4 bits per color mask.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0xf000</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x0f00</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0x00f0</td></tr>
	//- <tr><td>alpha mask</td><td>=</td><td>0x000f</td></tr>
	//- </table>
	static CL_PixelFormat rgba4444;

	//: Pixel format with 16 bit depth, 5 bits per color mask, one bit unused.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0x7c00</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x03e0</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0x001f</td></tr>
	//- <tr><td>alpha mask</td><td>=</td><td>0x0000</td></tr>
	//- </table>
	static CL_PixelFormat rgb555;

	//: Pixel format with 16 bit depth, 5 bits for red and blue, 6 bits for green.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0xf800</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x07e0</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0x001f</td></tr>
	//- <tr><td>alpha mask</td><td>=</td><td>0x0000</td></tr>
	//- </table>
	static CL_PixelFormat rgb565;

	//: Pixel format with 32 bit depth, 8 bits per color mask.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0x000000ff</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x0000ff00</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0x00ff0000</td></tr>
	//- <tr><td>alpha mask</td><td>=</td><td>0xff000000</td></tr>
	//- </table>
	static CL_PixelFormat abgr8888;

	//: Pixel format with 24 bit depth, 8 bits per color mask, no alpha.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0x0000ff</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x00ff00</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0xff0000</td></tr>
	//- </table>
	static CL_PixelFormat bgr888;

	//: Pixel format with 16 bit depth, 4 bits per color mask.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0x000f</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x00f0</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0x0f00</td></tr>
	//- <tr><td>alpha mask</td><td>=</td><td>0xf000</td></tr>
	//- </table>
	static CL_PixelFormat abgr4444;

	//: Pixel format with 16 bit depth, 5 bits per color mask, one bit unused.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0x001f</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x03e0</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0x7c00</td></tr>
	//- <tr><td>alpha mask</td><td>=</td><td>0x0000</td></tr>
	//- </table>
	static CL_PixelFormat bgr555;

	//: Pixel format with 16 bit depth, 5 bits for red and blue, 6 bits for green.
	//- <table>
	//- <tr><td>red mask</td>  <td>=</td><td>0x001f</td></tr>
	//- <tr><td>green mask</td><td>=</td><td>0x07e0</td></tr>
	//- <tr><td>blue mask</td> <td>=</td><td>0xf800</td></tr>
	//- <tr><td>alpha mask</td><td>=</td><td>0x0000</td></tr>
	//- </table>
	static CL_PixelFormat bgr565;

	//: Returns the shift of a color mask.
	static int get_mask_shift(unsigned int mask);
	
	//: Returns the bit count of a color mask.
	static int get_mask_bits(unsigned int mask);

	//: Returns the color mask based on bit count and shift.
	static unsigned int get_bitmask(int bits, int shift);

//! Operations:
public:
	//: Sets the pixel format type (RGB or Indexed).
	void set_type(CL_PixelFormatType new_type) { type = new_type; }

	//: Enable/disable color key.
	void enable_colorkey(bool enable = true) { colorkey_enabled = enable; }

	//: Sets the color key.
	void set_colorkey(unsigned int i) { colorkey = i; }

	//: Sets the depth of the pixel format.
	void set_depth(int i) { depth = i; }

	//: Sets the red component color mask.
	void set_red_mask(unsigned int i) { red_mask = i; }

	//: Sets the green component color mask.
	void set_green_mask(unsigned int i) { green_mask = i; }

	//: Sets the blue component color mask.
	void set_blue_mask(unsigned int i) { blue_mask = i; }

	//: Sets the alpha component color mask.
	void set_alpha_mask(unsigned int i) { alpha_mask = i; }

//! Implementation:
private:
	//: Pixel format type.
	CL_PixelFormatType type;

	//: True if colorkeying is enabled in the pixel format.
	bool colorkey_enabled;

	//: Colorkey value, if enabled.
	unsigned int colorkey;
	
	//: Bitmask marking the red component in a pixel.
	unsigned int red_mask;
	
	//: Bitmask marking the green component in a pixel.
	unsigned int green_mask;
	
	//: Bitmask marking the blue component in a pixel.
	unsigned int blue_mask;
	
	//: Bitmask marking the alpha component in a pixel.
	unsigned int alpha_mask;
	
	//: Bitdepth of a pixel.
	int depth;
};

#endif
