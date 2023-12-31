/*  $Id: frameratecounter.h,v 1.3 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_frameratecounter
#define header_frameratecounter

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/System/keep_alive.h"

class CL_FramerateCounter_Generic;

//: Framerate counter class.
//- !group=Display/Display 2D!
//- !header=display.h!
class CL_FramerateCounter : public CL_KeepAlive
{
//! Construction:
public:
	//: Constructs a framerate counter.
	CL_FramerateCounter();

//! Attributes:
public:
	int get_fps();

//! Implementation:
private:
	virtual void keep_alive();

	CL_FramerateCounter_Generic *impl;
};

#endif
