/*  $Id: fadefilter.h,v 1.12 2004/01/02 15:42:45 mbn Exp $
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

#ifndef header_fadefilter
#define header_fadefilter

#if _MSC_VER > 1000
#pragma once
#endif

#include "../soundfilter.h"

class CL_FadeFilter_Generic;

//: Fade Filter Class
//- !group=Sound/Filters!
//- !header=sound.h!
class CL_FadeFilter : public CL_SoundFilter
{
//! Construction:
public:
	//: Fade Filter Constructor
	CL_FadeFilter(float initial_volume);

	//: Fade Filter Destructor
	virtual ~CL_FadeFilter();

//! Attributes:
public:
	//: Returns the current volume of the fade filter, from 0.0f (no volume) to 1.0f (full volume).
	float get_volume() const;

//! Operations:
public:
	//: Sets the volume instant.
	void set_volume(float new_volume);
	
	//: Fade to volume, from 0.0f (no volume) to 1.0f (full volume).
	void fade_to_volume(float new_volume, int duration = 1000);

//! Overridables:
protected:
	virtual void filter(int **sample_data, int num_samples, int channels);

//! Implementation:
private:
	CL_FadeFilter(const CL_FadeFilter &copy) { return; } // disallow copy construction.

	CL_FadeFilter_Generic *impl;
};

#endif
