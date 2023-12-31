/*  $Id: inverse_echofilter.h,v 1.11 2004/01/02 15:42:45 mbn Exp $
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

#ifndef header_inverse_echofilter
#define header_inverse_echofilter

#if _MSC_VER > 1000
#pragma once
#endif

#include "../soundfilter.h"

class CL_InverseEchoFilter_Generic;

//: Inverse Echo Filter Class
//- !group=Sound/Filters!
//- !header=sound.h!
class CL_InverseEchoFilter : public CL_SoundFilter
{
//! Construction:
public:
	//: Inverse Echo Filter Constructor
	CL_InverseEchoFilter(int buffer_size = 64*1024);

	//: Inverse Echo Filter Destructor
	virtual ~CL_InverseEchoFilter();

//! Operations:
public:
	//: Filter
	virtual void filter(int **sample_data, int num_samples, int channels);

//! Implementation:
private:
	CL_InverseEchoFilter(const CL_InverseEchoFilter &copy) { return; } // disallow copy construction.
	CL_InverseEchoFilter_Generic *impl;
};

#endif
