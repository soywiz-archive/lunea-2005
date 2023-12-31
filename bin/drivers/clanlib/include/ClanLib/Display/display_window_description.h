/*  $Id: display_window_description.h,v 1.8 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_display_window_description
#define header_display_window_description

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>
#include "../Core/Math/rect.h"

class CL_DisplayWindowDescription_Generic;

//: Display window description class.
//- !group=Display/Display 2D!
//- !header=display.h!
//- <p>This class allows you to setup a more advanced description when creating
//- a display window.</p>
class CL_DisplayWindowDescription
{
//! Construction:
public:
	//: Constructs a window description with default values.
	CL_DisplayWindowDescription();

	CL_DisplayWindowDescription(const CL_DisplayWindowDescription &copy);

	virtual ~CL_DisplayWindowDescription();

//! Attributes:
public:
	//: Returns the window title stored in the description.
	const std::string &get_title() const;

	//: Returns the size of the window stored in description.
	CL_Size get_size() const;

	//: Returns the initial position of the window.
	CL_Rect get_position() const;

	//: Returns if window should be initially fullscreen.
	bool is_fullscreen() const;

	//: Returns the amount of flipping buffers to be created.
	int get_flipping_buffers() const;

	//: Returns true if window should be resizeable.
	bool get_allow_resize() const;
	
	//: Returns the numbers of bytes per pixel in the window.
	int get_bpp() const;

	//: Returns the refresh rate of the displaymode.
	//- <p>Specifies the frequency, in hertz (cycles per second).
	//- This value is also known as the vertical refresh rate.</p> 
	int get_refresh_rate() const;

#ifdef WIN32
	//: Windows 2000/XP only. Returns true if window is layered.
	bool is_layered() const;
#endif

//! Operations:
public:
	//: Copy assignment operator.
	CL_DisplayWindowDescription &operator =(const CL_DisplayWindowDescription &copy);

	//: Sets the title of the window.
	void set_title(const std::string &title);

	//: Sets the size of the window.
	void set_size(const CL_Size &size);

	//: Sets the position of the window.
	void set_position(const CL_Rect &position);

	//: Makes the window initially fullscreen.
	void set_fullscreen(bool fullscreen = true);

	//: Sets the amount of flipping buffers to be used.
	void set_flipping_buffers(int num_buffers = 2);

	//: Sets if windows should be resizeable.
	void set_allow_resize(bool allow_resize);
	
	//: Sets the number of bytes per pixel
	void set_bpp(int bpp);

	//: Set the refresh rate of the displaymode.
	//- <p>Specifies the frequency, in hertz (cycles per second).
	//- This value is also known as the vertical refresh rate.</p> 
	void set_refresh_rate(int refresh_rate);

#ifdef WIN32
	//: Windows 2000/XP only. Creates a layered window (complex shaped window).
	void set_layered(bool layered);
#endif

//! Implementation:
protected:
	CL_DisplayWindowDescription(CL_DisplayWindowDescription_Generic *impl);

public:
	CL_DisplayWindowDescription_Generic *impl;
};

#endif
