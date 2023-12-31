/*  $Id: provider_type.h,v 1.9 2004/01/02 15:42:43 mbn Exp $
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

//! clanDisplay="Surface Providers"
//! header=display.h

#ifndef header_provider_type
#define header_provider_type

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_PixelBuffer;
class CL_InputSourceProvider;

//: Provider type
//- !group=Display/Surface Providers!
//- !header=display.h!
class CL_ProviderType
{
//! Construction:
public:
	//: Registers a provider type in the CL_ProviderFactory.
	CL_ProviderType(const std::string &type);

	//: Unregisters a provider type in the CL_ProviderFactory.
	virtual ~CL_ProviderType();

//! Operations:
public:
	//: Called to load an image with this provider type.
	virtual CL_PixelBuffer *load(
		const std::string &filename,
		CL_InputSourceProvider *input_provider)=0;

//! Implementation:
private:
};

#endif
