/*  $Id: dom_implementation.h,v 1.8 2004/02/01 04:31:55 mbn Exp $
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

//! clanCore="XML"
//! header=core.h

#ifndef header_dom_implementation
#define header_dom_implementation

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"

class CL_DomImplementation_Generic;
class CL_DomDocument;

//: DOM Implementation class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>The DOM Implementation interface provides a number of methods for performing
//- operations that are independent of any particular instance of the document object model.</p>
class CL_DomImplementation
{
//! Construction:
public:
	//: Constructs a DOM Implementation handle.
	CL_DomImplementation();

	CL_DomImplementation(CL_DomDocument &doc);

	~CL_DomImplementation();

//! Attributes:
public:

//! Operations:
public:
	//: Test if the DOM implementation implements a specific feature.
	//param feature: The package name of the feature to test. In Level 1, the legal values are "HTML" and "XML" (case-insensitive).
	//param version: This is the version number of the package name to test. In Level 1, this is the string "1.0". If the version is not specified, supporting any version of the feature will cause the method to return true.
	//retval: true if the feature is implemented in the specified version, false otherwise.
	bool has_feature(const std::string &feature, const std::string &version);

//! Implementation:
private:
	CL_SharedPtr<CL_DomImplementation_Generic> impl;
};

#endif
