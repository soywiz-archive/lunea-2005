/*  $Id: soundprovider_type_register.h,v 1.6 2004/01/02 15:42:45 mbn Exp $
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

#ifndef header_soundprovider_type_register
#define header_soundprovider_type_register

#if _MSC_VER > 1000
#pragma once
#endif

#include "soundprovider_type.h"

//: Class template to register a sound provider type.
//- !group=Sound/Sound Providers!
//- !header=sound.h!
template<class SoundProviderClass>
class CL_SoundProviderType_Register : public CL_SoundProviderType
{
//! Construction:
public:
	//: Registers sound provider type in the CL_SoundProviderFactory.
	CL_SoundProviderType_Register(const std::string &type) : CL_SoundProviderType(type)
	{
	}

//! Operations:
public:
	//: Called to load static with this sound provider type.
	virtual CL_SoundProvider *load(
		const std::string &filename,
		CL_InputSourceProvider *input_provider,
		bool stream)
	{
		return new SoundProviderClass(filename, input_provider, stream);
	}
};

#endif
