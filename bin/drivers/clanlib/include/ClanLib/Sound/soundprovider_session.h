/*  $Id: soundprovider_session.h,v 1.9 2004/02/01 20:28:56 mbn Exp $
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

#ifndef header_soundprovider_session
#define header_soundprovider_session

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/System/mutexsharedptr.h"
#include "soundformat.h"

class CL_SoundProvider_Session_Generic;

//: Sound provider playback session.
//- !group=Sound/Audio Mixing!
//- !header=sound.h!
//- <p>Interface used by ClanLib during playback of sound providers.</p>
class CL_SoundProvider_Session
{
//! Construction:
public:
	CL_SoundProvider_Session();

	CL_SoundProvider_Session(const CL_SoundProvider_Session &copy);

	virtual ~CL_SoundProvider_Session();

//! Attributes:
public:
	//: Returns the number of samples in the soundbuffer.
	virtual int get_num_samples() const = 0;

	//: Returns the playback frequency of the input data.
	//return: Playback frequency.
	virtual int get_frequency() const = 0;

	//: Returns the current position in the playback stream.
	virtual int get_position() const = 0;

	//: Returns the playback sample format.
	//return: The playback Sample format.
	virtual CL_SoundFormat get_format() const = 0;

	//: Returns the number of channels filled when get_data is called.
	virtual int get_num_channels() const = 0;

//! Operations:
public:
	//: Enable/disable session looping.
	//- <p>If this function returns false (default), the clanSound mixer will manually
	//- try to simulate looping by setting the position to 0 when eof is encountered.</p>
	virtual bool set_looping(bool loop) { return false; }

	//: Returns true if no more input data is available.
	//return: True if end of input data. False otherwise.
	virtual bool eof() const = 0;
	
	//: Stops the current stream.
	virtual void stop() = 0;

	//: Start/continue playing of the stream.
	//return: True for success. False otherwise.
	virtual bool play() = 0;
		
	//: Sets the position within the current stream.
	//param pos: Position to seek to.
	//return: True for success. False otherwise.
	virtual bool set_position(int pos) = 0;
	
	//: Called when a playback session needs more sample data.
	//param data_ptr: Points to a buffer that should be filled with sample data.
	//param data_requested: Samples of data requested.
	//return: Number of samples actually filled with sample data.
	virtual int get_data(void **data_ptr, int data_requested) = 0;

//! Implementation:
private:
	CL_MutexSharedPtr<CL_SoundProvider_Session_Generic> impl;
};

#endif
