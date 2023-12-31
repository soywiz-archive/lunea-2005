/*  $Id: palette.h,v 1.11 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_palette
#define header_palette

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include "color.h"
#include <string.h>

//: 256 color ARGB palette class.
//- !group=Display/Display 2D!
//- !header=display.h!
class CL_Palette
{
//! Construction:
public:
	//: Constructs a palette.
	//param copy: Integer array of ARGB8888 color components to use as initial palette.
	CL_Palette() { return; }

	CL_Palette(const unsigned int *copy) { memcpy(colors, copy, sizeof(int)*256); }

//! Attributes:
public:
	//: Palette color entries.
	CL_Color colors[256];

	//: Return color at index.
	const CL_Color &operator[](int index) const { return colors[index]; }

	CL_Color &operator[](int index) { return colors[index]; }

	//: Returns the palette in ARGB8888 format.
	operator const unsigned int*() const { return (const unsigned int *) colors; }

	operator unsigned int*() const { return (unsigned int *) colors; }
};

#endif
