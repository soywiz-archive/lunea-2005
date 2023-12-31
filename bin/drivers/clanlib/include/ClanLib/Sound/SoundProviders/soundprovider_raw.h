/*  $Id: soundprovider_raw.h,v 1.4 2004/01/02 15:42:45 mbn Exp $
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

//! clanSound="Sound Providers"
//! header=sound.h

#ifndef header_sound_provider_raw
#define header_sound_provider_raw

#if _MSC_VER > 1000
#pragma once
#endif

#include "../soundprovider.h"

class CL_SoundProvider_Raw_Generic;

//: Sound provider in a raw PCM format (no header in file).
//- !group=Sound/Sound Providers!
//- !header=sound.h!
class CL_SoundProvider_Raw : public CL_SoundProvider
{
//! Construction:
public:
	//: Constructs a sound provider based on some raw PCM data.
	//param sound_data: Raw PCM data.
	//param num_samples: Number of samples to be read out of sound_data.
	//param bytes_per_sample: The size of a sample in bytes. This is 2 for 16 bit, and 1 for 8 bit.
	//param stereo: True if sound is stereo (two channels).
	//param frequency: Playback frequency for sample data.
	CL_SoundProvider_Raw(
		void *sound_data,
		int num_samples,
		int bytes_per_sample,
		bool stereo,
		int frequency = 22050);

	virtual ~CL_SoundProvider_Raw();

//! Operations:
public:
	//: Called by CL_SoundBuffer when a new session starts.
	//return: The soundbuffer session to be attached to the newly started session.
	virtual CL_SoundProvider_Session *begin_session();

	//: Called by CL_SoundBuffer when a session has finished. After this call,
	//- <p>CL_SoundBuffer will not access the session anymore. It can safely be deleted
	//- here (and in most cases should be delete here).</p>
	virtual void end_session(CL_SoundProvider_Session *session);

//! Implementation:
private:
	CL_SoundProvider_Raw_Generic *impl;
};

#endif
