/*  $Id: echofilter.h,v 1.11 2004/01/02 15:42:44 mbn Exp $
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

//! clanSound="Filters"
//! header=sound.h

#ifndef header_echofilter
#define header_echofilter

#if _MSC_VER > 1000
#pragma once
#endif

#include "../soundfilter.h"

class CL_EchoFilter_Generic;

//: Echo Filter Class
//- !group=Sound/Filters!
//- !header=sound.h!
class CL_EchoFilter : public CL_SoundFilter
{
//! Construction:
public:
	//: Echo Filter Constructor
	CL_EchoFilter(int buffer_size = 32*1024, int shift_factor = 2);

	//: Echo Filter Destructor
	virtual ~CL_EchoFilter();

//! Operations:
public:
	//: Filter
	virtual void filter(int **sample_data, int num_samples, int channels);

//! Implementation:
private:
	CL_EchoFilter(const CL_EchoFilter &copy) { return; } // disallow copy construction.
	CL_EchoFilter_Generic *impl;
};

#endif
