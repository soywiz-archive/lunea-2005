/*  $Id: soundoutput.h,v 1.6 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_soundoutput
#define header_soundoutput

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_SoundFilter;
class CL_SoundBuffer;
class CL_SoundOutput_Description;
class CL_SoundOutput_Generic;

//: SoundOutput interface in ClanLib.
//- !group=Sound/Audio Mixing!
//- !header=sound.h!
//- <p>CL_SoundOutput is the interface to a sound output device. It is used to
//- control the main mixer volume and other global settings.</p>
class CL_SoundOutput
{
//! Construction:
public:
	//: Constructs a sound output object.
	CL_SoundOutput();

	CL_SoundOutput(int mixing_frequency);

	CL_SoundOutput(const CL_SoundOutput_Description &desc);

	CL_SoundOutput(const CL_SoundOutput &copy);

	virtual ~CL_SoundOutput();

//! Attributes:
public:
	//: Name of the output device.
	const std::string &get_name() const;

	//: Returns the mixing frequency for the sound output device.
	int get_mixing_frequency() const;

	//: Returns the main volume of the sound output.
	float get_global_volume() const;

	//: Returns the main panning position of the sound output.
	float get_global_pan() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_SoundOutput &operator =(const CL_SoundOutput &copy);

	//: Stops all sample playbacks on the sound output.
	void stop_all();
	
	//: Sets the main/mixer volume on the sound output.
	void set_global_volume(float volume);

	//: Sets the main panning position on the sound output.
	void set_global_pan(float pan);

	//: Adds the sound filter to the sound output.
	//param filter: Sound filter to pass sound through.
	//param delete_filter: If true, the filter will be deleted when the sound output is destroyed.
	void add_filter(CL_SoundFilter *filter, bool delete_filter = false);

	//: Remove the sound filter from the session.
	void remove_filter(CL_SoundFilter *filter);

//! Implementation:
private:
	CL_SoundOutput_Generic *impl;

	friend class CL_SoundBuffer;
};

#endif
