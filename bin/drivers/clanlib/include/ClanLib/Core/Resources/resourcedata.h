/*  $Id: resourcedata.h,v 1.13 2004/01/02 15:42:43 mbn Exp $
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

//! clanCore="Resources"
//! header=core.h

#ifndef header_resourcedata
#define header_resourcedata

#if _MSC_VER > 1000
#pragma once
#endif

#include "resource.h"

class CL_ResourceData_Generic;

//: Data object attached to a resource.
//- !group=Core/Resources!
//- !header=core.h!
//- <p>The CL_ResourceData class represents a data object connected to a
//- resource. A resource can have one or more of these data objects
//- attached, and they can be retrieved by making a call to
//- CL_Resource::get_data.</p>
//- <p>Resource data objects are used to contain extra data associated with
//- a certain resource. For instance, the surface resource has an object
//- attached by the name "surface" that contain the loaded surface's
//- data.</p>
class CL_ResourceData
{
//! Construction:
public:
	//: Constructs a resource data object.
	//- <p>A resource data object will not by itself attach to a
	//- CL_Resource. This must be done manually by making a call to
	//- CL_Resource::attach_data.</p>
	//param resource: Resource object associated with this resource data
	//param resource: object.
	CL_ResourceData(CL_Resource &resource);

	//: Resource Data destructor.
	virtual ~CL_ResourceData();

//! Attributes:
public:
	//: Get Resource object.
	CL_Resource get_resource();

//! Operations:
public:
	//: Called first time CL_Resource::load() is called on the resource.
	virtual void on_load() { return; }

	//: Called last time CL_Resource::unload() is called on the resource.
	virtual void on_unload() { return; }

//! Implementation:
private:
	//: Pointer to the implementation.
	CL_ResourceData_Generic *impl;
};

#endif
