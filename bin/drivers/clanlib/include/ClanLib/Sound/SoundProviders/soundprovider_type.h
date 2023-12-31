/*  $Id: soundprovider_type.h,v 1.6 2004/01/02 15:42:45 mbn Exp $
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

#ifndef header_soundprovider_type
#define header_soundprovider_type

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_SoundProvider;
class CL_InputSourceProvider;

//: Sound provider type
//- !group=Sound/Sound Providers!
//- !header=sound.h!
class CL_SoundProviderType
{
//! Construction:
public:
	//: Registers a sound provider type in the CL_SoundProviderFactory.
	CL_SoundProviderType(const std::string &type);

	//: Unregisters a sound provider type in the CL_SoundProviderFactory.
	virtual ~CL_SoundProviderType();

//! Operations:
public:
	//: Called to load with this sound provider type.
	virtual CL_SoundProvider *load(
		const std::string &filename,
		CL_InputSourceProvider *input_provider,
		bool streamed) = 0;

//! Implementation:
private:
};

#endif
