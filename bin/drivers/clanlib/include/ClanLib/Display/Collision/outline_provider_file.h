/*  $Id: outline_provider_file.h,v 1.2 2004/04/05 09:51:58 sphair Exp $
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

//! clanDisplay="Collision"
//! header=display.h

#ifndef header_outline_provider_file
#define header_outline_provider_file

#if _MSC_VER > 1000
#pragma once
#endif

#include "outline_provider.h"

class CL_OutlineProviderFile_Generic;
class CL_InputSourceProvider;

//: File outline provider is used to load precompiled outlines.
//- !group=Display/Collision !
//- !header=display.h!
//- <p>A CL_OutlineProviderFile is used to load precompiled outlines.</p>
class CL_OutlineProviderFile : public CL_OutlineProvider
{
//! Construction:
 public:
	//: Construct a outline provider
	//param std::string filename : Name of file to load.
	//param CL_InputSourceProvider *provider : (optional) Use this input source provider as source of data.
	CL_OutlineProviderFile(const std::string &filename, CL_InputSourceProvider *provider=0);
	~CL_OutlineProviderFile();

//! Attributes:
 public:
	//: return the countours that make up the outline
	virtual std::vector<CL_Contour> get_contours();

	//: Not used for file provider. Returns -1.
	virtual int get_width();

	//: Not used for file provider. Returns -1.
	virtual int get_height();

//! Implementation:
 private:
	CL_OutlineProviderFile_Generic *impl;
};

#endif
