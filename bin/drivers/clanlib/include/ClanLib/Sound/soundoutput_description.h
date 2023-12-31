/*  $Id: soundoutput_description.h,v 1.4 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_soundoutput_description
#define header_soundoutput_description

#if _MSC_VER > 1000
#pragma once
#endif

class CL_SoundOutput_Description_Generic;

//: Sound output description class.
//- !group=Sound/Audio Mixing!
//- !header=sound.h!
class CL_SoundOutput_Description
{
//! Construction:
public:
	//: Constructs a sound output description.
	CL_SoundOutput_Description();

	CL_SoundOutput_Description(const CL_SoundOutput_Description &copy);

	~CL_SoundOutput_Description();

//! Attributes:
public:
	//: Returns the mixing frequency for the sound output device.
	int get_mixing_frequency() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_SoundOutput_Description &operator =(const CL_SoundOutput_Description &copy);

	//: Sets the mixing frequency for the sound output device.
	void set_mixing_frequency(int frequency);

//! Implementation:
private:
	CL_SoundOutput_Description_Generic *impl;
};

#endif
