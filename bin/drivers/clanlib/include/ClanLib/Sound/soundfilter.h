/*  $Id: soundfilter.h,v 1.13 2004/01/02 15:42:44 mbn Exp $
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

//! clanSound="Audio Mixing"
//! header=sound.h

#ifndef header_soundfilter
#define header_soundfilter

#if _MSC_VER > 1000
#pragma once
#endif

class CL_SoundFilter_Generic;

//: Sound Filter Class
//- !group=Sound/Audio Mixing!
//- !header=sound.h!
class CL_SoundFilter
{
//! Construction:
public:
	//: Sound filter constructor.
	CL_SoundFilter();

	CL_SoundFilter(const CL_SoundFilter &copy);

	//: Sound Filter Destructor
	virtual ~CL_SoundFilter();
	
//! Operations:
public:
	//: Copy assignment operator.
	CL_SoundFilter &operator =(const CL_SoundFilter &copy);

//! Overridables:
	//: Filter callback.
	//- <p>All sound data is passed through this function,
	//- which modifies the sample data accordingly to the function of the
	//- filter.</p>
	//- <p>The format of the sample data is always 16 bit stereo. </p>
	virtual void filter(int **sample_data, int num_samples, int channels)=0;

//! Implementation:
public:
	CL_SoundFilter_Generic *impl;
};

#endif
