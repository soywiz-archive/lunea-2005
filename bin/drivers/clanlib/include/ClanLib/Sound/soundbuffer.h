/*  $Id: soundbuffer.h,v 1.21 2004/02/01 20:28:56 mbn Exp $
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

#ifndef header_soundbuffer
#define header_soundbuffer

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/System/mutexsharedptr.h"
#include "../Core/Resources/resource.h"
#include "soundbuffer_session.h"

class CL_ResourceManager;
class CL_SoundOutput;
class CL_SoundProvider;
class CL_SoundBuffer_Session;
class CL_SoundFilter;
class CL_SoundBuffer_Generic;

class CL_SoundBuffer
//: Sample interface in ClanLib.
//- !group=Sound/Audio Mixing!
//- !header=sound.h!
//- <p>The CL_SoundBuffer class represents a sample in ClanLib. It can
//- either be static or streamed. The soundbuffer gets its sample data from
//- a soundprovider, that is passed during construction.</p>
//also: CL_SoundProvider
//also: CL_SoundProvider_Session
//also: CL_SoundBuffer_Session
{
//! Construction:
public:
	//: Construct sound buffer.
	//- <p>A sound buffer can be constructed either as static or
	//- streamed. If the sound buffer is loaded from resources, the
	//- buffer type is determined by the resource option 'stream'
	//- associated with the resource.</p>
	//-
	//- <p>CL_SoundBuffer's internals are reference counted, so the copy
	//- constructor will create a new soundbuffer object which shares
	//- the same buffer as the original one. This means that if the copy
	//- is modified, the original is affected as well.</p>
	//-
	//- <p>If <i>delete_provider</i> is true, the provider will be
	//- deleted when the soundbuffer is deleted.</p>
	
	CL_SoundBuffer();
	
	CL_SoundBuffer(
		const std::string &res_id,
		CL_ResourceManager *manager);

	CL_SoundBuffer(
		CL_SoundProvider *provider,
		bool delete_provider = false);

	CL_SoundBuffer(
		const std::string &filename,
		bool streamed = false,
		const std::string &format = "");

	CL_SoundBuffer(const CL_SoundBuffer &copy);

	virtual ~CL_SoundBuffer();

//! Attributes:
public:
	//: Returns the sound provider to be used for playback.
	CL_SoundProvider *get_sound_provider() const;

	//: Returns the start/default volume used when the buffer is played.
	float get_volume() const;

	//: Returns the default panning position when the buffer is played.
	float get_pan() const;

	//: Returns true if an instance of this soundbuffer is playing
	bool is_playing() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_SoundBuffer &operator =(const CL_SoundBuffer &copy);

	//: Sets the volume of the sound buffer in a relative measure (0->1)
	//- <p>A value of 0 will effectively mute the sound (although it will
	//- still be sampled), and a value of 1 will set the volume to "max".</p>
	//param new_volume: New volume of sound buffer. 
	void set_volume(float new_volume);

	//: Sets the panning of the sound buffer played in measures from -1 -> 1
	//- <p>Setting the pan with a value of -1 will pan the sound buffer to the
	//- extreme left (left speaker only), 1 will pan the sound buffer to the
	//- extreme right (right speaker only).</p>
	//param new_pan: New pan of the sound buffer played.
	void set_pan(float new_pan);

	//: Adds the sound filter to the sound buffer.
	//param filter: Sound filter to pass sound through.
	//param delete_filter: If true, the filter will be deleted when the sound output is destroyed.
	void add_filter(CL_SoundFilter *filter, bool delete_filter = false);

	//: Remove the sound filter from the sound buffer.
	void remove_filter(CL_SoundFilter *filter);

	//: Stops any sessions playing this soundbuffer
	void stop();

	//: Plays the soundbuffer on the specified soundcard.
	//param output: Sound output to be used - NULL means use the current selected sound output (CL_Sound::get_selected_output().
	//return: The playback session.
	CL_SoundBuffer_Session play(bool looping = false, CL_SoundOutput *output = 0);

	//: Prepares the soundbuffer for playback on the specified soundcard.
	//param output: Sound output to be used - NULL means use the current selected sound output (CL_Sound::get_selected_output().
	//return: The playback session.
	CL_SoundBuffer_Session prepare(bool looping = false, CL_SoundOutput *output = 0);

//! Implementation:
private:
	CL_Resource resource;

	CL_MutexSharedPtr<CL_SoundBuffer_Generic> impl;
};

#endif
