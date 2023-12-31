/*  $Id: sound.h,v 1.13 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_sound
#define header_sound

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_SoundOutput;

class CL_Sound
//: Sound interface in ClanLib.
//- !group=Sound/Audio Mixing!
//- !header=sound.h!
//- <p>All the functions that share name with those in CL_SoundOutput have the
//- same functionality. The only difference is, that the ones CL_Sound
//- operate on a selected sound output. This saves the trouble of passing around
//- a pointer to the sound output, when only a single one is used anyway.</p>
//also: CL_SoundOutput - Sound Output interface class.
//also: CL_SoundBuffer - Sample class in ClanLib.
{
//! Selected CL_SoundOutput accessors:
public:
	//: Returns the name of the current sound output:
	static const std::string &get_name();

	//: Returns the mixing frequency of the current sound output.
	static int get_mixing_frequency();

	//: Returns the current selected sound output.
	static CL_SoundOutput *get_current_output();

	//: Change the current selected sound output.
	//param output: The new current selected sound output.
	static void select_output(CL_SoundOutput *output);
};

#endif
