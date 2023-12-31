/*  $Id: display_mode.h,v 1.13 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_display_mode
#define header_display_mode

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include <vector>
#include <string>

class CL_Size;
class CL_DisplayMode_Generic;

//: Display mode class.
//- !group=Display/Display 2D!
//- !header=display.h!
//- <p>This class contains information about one display mode available.
//- It also contains a static function to get a list of all available display modes.</p>
//- <p>Code example which dumps a list over all available modes:</p>
//- <pre>
//- std::vector < CL_DisplayMode > &modes = CL_DisplayMode::get_display_modes();
//- for(unsigned int i=0; i < modes.size(); ++i)
//-     std::cout << modes[i].get_string() << std::endl;
//- </pre>
class CL_DisplayMode
{
//! Construction:
public:
	CL_DisplayMode(const CL_Size &res, int bpp, int refresh_rate);

	CL_DisplayMode(const CL_DisplayMode &copy);

	virtual ~CL_DisplayMode();

//! Attributes:
public:
	//: Returns the resolution of the displaymode.
	CL_Size get_resolution() const;

	//: Returns the numbers of bytes per pixel of the displaymode.
	int get_bpp() const;

	//: Returns the refresh rate of the displaymode.
	//- <p>Specifies the frequency, in hertz (cycles per second).
	//- This value is also known as the vertical refresh rate.</p>
	int get_refresh_rate() const;

	//: Returns the information as a string in the format "640x480x32@60"
	std::string get_string() const;

	//: Returns a list over all available display modes.
	static std::vector<CL_DisplayMode> &get_display_modes();

//! Operations:
public:
	//: Copy assignment operator.
	CL_DisplayMode &operator =(const CL_DisplayMode &copy);

//! Implementation:
private:
	CL_DisplayMode_Generic *impl;
};

#endif
