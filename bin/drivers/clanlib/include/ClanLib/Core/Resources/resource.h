/*  $Id: resource.h,v 1.30 2004/02/01 01:54:16 mbn Exp $
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

#ifndef header_resource
#define header_resource

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"
#include "../../signals.h"
#include <string>

class CL_ResourceManager;
class CL_ResourceData;
class CL_Resource_Generic;

#include "../XML/dom_element.h"

//: Interface for accessing a resource in the resource manager.
//- !group=Core/Resources!
//- !header=core.h!
class CL_Resource
{
//! Construction:
public:
	//: Resource constructor.
	CL_Resource(
		CL_DomElement &element,
		CL_ResourceManager *manager);

	CL_Resource(const CL_Resource &copy);

	CL_Resource();

	//: Resource destructor.
	virtual ~CL_Resource();

//! Attributes:
public:
	//: Returns the type of the resource.
	std::string get_type() const;

	//: Returns the name of the resource.
	std::string get_name() const;

	//: Returns the resource DOM element.
	CL_DomElement &get_element();

	//: Returns the resource manager.
	CL_ResourceManager get_manager();

	//: Returns the data with the matching name.
	CL_ResourceData *get_data(const std::string &name);

	//: Returns the current reference count.
	int get_reference_count() const;

//! Operations:
public:
	//: Attach some data to the resource.
	void attach_data(const std::string &name, CL_ResourceData *data);

	//: Detach some data from the resource.
	void detach_data(CL_ResourceData *data);

	//: Unloads the resource from memory.
	void unload();

	//: Loads the resource, using the prefered source as specified by
	//: the resource manager.
	void load();

//! Implementation:
private:
	CL_Resource(const CL_SharedPtr<CL_Resource_Generic> &impl);

	//: Pointer to implementation
	CL_SharedPtr<CL_Resource_Generic> impl;

	friend class CL_ResourceData;
	friend class CL_ResourceManager_Generic;
};

#endif
