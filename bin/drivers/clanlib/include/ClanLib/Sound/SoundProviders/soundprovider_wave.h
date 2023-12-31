/*  $Id: soundprovider_wave.h,v 1.6 2004/01/02 15:42:45 mbn Exp $
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

#ifndef header_sound_provider_wave
#define header_sound_provider_wave

#if _MSC_VER > 1000
#pragma once
#endif

#include "../soundprovider.h"
#include <string>

class CL_InputSourceProvider;
class CL_SoundProvider_Wave_Generic;

//: Windows WAVE sample format (.wav) sound provider.
//- !group=Sound/Sound Providers!
//- !header=sound.h!
class CL_SoundProvider_Wave : public CL_SoundProvider
{
//! Construction:
public:
	//: Constructs a sound provider based on a Windows wave (.wav) file.
	//param filename: Filename of wave file.
	//param provider: Input source provider used to retrieve wave file.
	//param stream: If true, will stream from disk. If false, will load it to memory.
	CL_SoundProvider_Wave(
		const std::string &filename,
		CL_InputSourceProvider *provider = 0,
		bool stream = false);

	virtual ~CL_SoundProvider_Wave();

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
	CL_SoundProvider_Wave_Generic *impl;
};

#endif
