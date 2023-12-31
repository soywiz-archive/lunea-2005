/*  $Id: soundbuffer_session.h,v 1.16 2004/02/01 20:28:56 mbn Exp $
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

#ifndef header_soundbuffer_session
#define header_soundbuffer_session

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/System/mutexsharedptr.h"

class CL_SoundCard;
class CL_SoundFilter;
class CL_SoundBuffer;
class CL_SoundBuffer_Session_Generic;

class CL_SoundBuffer_Session
//: CL_SoundBuffer_Session provides control over a playing soundeffect.
//- !group=Sound/Audio Mixing!
//- !header=sound.h!
//- <p>Whenever a soundbuffer is played, it returns a CL_SoundBuffer_Session
//- class, which can be used to control the sound (its volume, pitch, 
//- pan, position). It can also be used to retrigger the sound
//- or to stop it.</p>
{
//! Construction:
public:
	//: Creates a soundbuffer session.
	CL_SoundBuffer_Session();

	CL_SoundBuffer_Session(const CL_SoundBuffer_Session &copy);

	virtual ~CL_SoundBuffer_Session();

//! Attributes:
public:
	//: Returns the current sample position of the playback.
	int get_position() const;
	
	//: Returns the sample position relative to the full length.
	//- <p>The value returned will be between 0 and 1, where 0
	//- means the session is at the beginning, and 1
	//- means that the soundeffect has reached the end.</p>
	float get_position_relative() const;

	//: Returns the total length (in samples) of the sound buffer played.
	//- <p>Value returned will be -1 if the length is unknown (in
	//- case of non-static soundeffects like streamed sound)</p>
	int get_length() const;

	//: Returns the frequency of the session.
	int get_frequency() const;

	//: Returns the linear relative volume of the soundeffect.
	//- <p>0 means the soundeffect is muted, 1 means the soundeffect
	//- is playing at "max" volume.</p>
	float get_volume() const;
	
	//: Returns the current pan (in a measure from -1 -> 1).
	//- <p>-1 means the soundeffect is only playing in the left speaker, 
	//- and 1 means the soundeffect is only playing in the right speaker.</p>
	float get_pan() const;

	//: Returns true if the session is playing
	bool is_playing();

//! Operations:
public:
	//: Sets the session position to 'new_pos'.
	//- <p>The new position of the session.</p>
	//return: Returns true if operation completed succesfully.
	bool set_position(int new_pos);

	//: Sets the relative position of the session.
	//- <p>Value must be between 0 and 1, where 0 sets the 
	//- session to the beginning, and 1 sets it
	//- to the end of the sound buffer.</p>
	//param new_pos: New relative position.
	//return: Returns true if operation completed succesfully.
	bool set_position_relative(float new_pos);
	
	//: Sets the frequency of the session.
	//param new_freq: New frequency of session.
	//return: Returns true, if the operation completed succesfully.
	bool set_frequency(int new_freq);
	
	//: Sets the volume of the session in a relative measure (0->1)
	//- <p>A value of 0 will effectively mute the sound (although it will
	//- still be sampled), and a value of 1 will set the volume to "max".</p>
	//param new_volume: New volume of session. 
	//return: Returns true if the operation completed succesfully.
	void set_volume(float new_volume);

	//: Sets the panning of the session played in measures from -1 -> 1
	//- <p>Setting the pan with a value of -1 will pan the session to the
	//- extreme left (left speaker only), 1 will pan the session to the
	//- extreme right (right speaker only).</p>
	//param new_pan: New pan of the session played.
	//return: Returns true if the operation completed sucecsfully.
	void set_pan(float new_pan);

	//: Starts playback of the session.
	void play();

	//: Stops playback of the session.
	void stop();

	//: Determines whether this session should loop
	//param loop: true if session should loop, false otherwise
	void set_looping(bool loop);
	
	//: Adds the sound filter to the session. See CL_SoundFilter for details.
	//param filter: Sound filter to pass sound through.
	//param delete_filter: If true, the filter will be deleted when the session is destroyed
	void add_filter(CL_SoundFilter *filter, bool delete_filter = false);

	//: Remove the sound filter from the session. See CL_SoundFilter for details.
	void remove_filter(CL_SoundFilter *filter);

//! Implementation:
private:
	CL_SoundBuffer_Session(const CL_MutexSharedPtr<CL_SoundBuffer_Session_Generic> &impl);

	CL_MutexSharedPtr<CL_SoundBuffer_Session_Generic> impl;

	friend class CL_SoundBuffer;
};

#endif
