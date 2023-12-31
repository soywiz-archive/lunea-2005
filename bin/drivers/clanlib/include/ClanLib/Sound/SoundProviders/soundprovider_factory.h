/*  $Id: soundprovider_factory.h,v 1.6 2004/01/02 15:42:45 mbn Exp $
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

#ifndef header_soundprovider_factory
#define header_soundprovider_factory

#if _MSC_VER > 1000
#pragma once
#endif

#include <map>
#include <string>

class CL_SoundProvider;
class CL_InputSourceProvider;
class CL_SoundProviderType;

//: Sound Provider Factor class.
//- !group=Sound/Sound Providers!
//- !header=sound.h!
class CL_SoundProviderFactory
{
//! Attributes:
public:
	//: Map of the class factories for each sound provider type.
	static std::map<std::string, CL_SoundProviderType *> types;

//! Operations:
public:
	//: Loads an sample file from 'filename', using the provider
	//: identified by 'type'.
	//- <p>If the type is an empty string, it
	//- uses the extension of the filename to determine what type
	//- it is.</p>
	//- <p>The input provider will be used as a the source for filename,
	//- if specified.</p>
	static CL_SoundProvider *load(
		const std::string &filename,
		bool streamed = false,
		const std::string &type = "",
		CL_InputSourceProvider *input_provider = 0);
};

#endif
