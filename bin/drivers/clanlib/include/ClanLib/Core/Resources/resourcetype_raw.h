/*  $Id: resourcetype_raw.h,v 1.19 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_resourcetype_raw
#define header_resourcetype_raw

#if _MSC_VER > 1000
#pragma once
#endif

#include "resourcedata.h"
#include "resource_manager.h"
#include "resource.h"
#include "../IOData/inputsource_memory.h"
#include <string>
#include <vector>

//: Resource Data object for a 'raw' resource type.
//- !group=Core/Resources!
//- !header=core.h!
class CL_ResourceData_Raw : public CL_ResourceData
{
//! Construction:
public:
	//: Resource Data Raw Constructor.
	CL_ResourceData_Raw(class CL_Resource &resource);

//! Attributes:
public:
	//: Vector array containing the raw data.
	std::vector<unsigned char> value;

//! Implementation:
private:
	void on_load();

	void on_unload();
};

//: Raw resource accessor class.
//- !group=Core/Resources!
//- !header=core.h!
class CL_Raw
{
//! Construction:
public:
	//: Constructs an raw object.
	//param res_id: Resource id of an raw resource to load from.
	//param resources: Resource manager to load resource from.
	CL_Raw(const std::string &res_id, CL_ResourceManager *resources)
	{
		res = resources->get_resource(res_id);
		res.load();
		data = (CL_ResourceData_Raw *) res.get_data("raw");
	}

	//: Raw Class destructor.
	~CL_Raw()
	{
		res.unload();
	}

//! Attributes:
public:
	//: Returns the raw data as a vector.
	std::vector<unsigned char> &get_data()
	{
		return data->value;
	}

	const std::vector<unsigned char> &get_data() const
	{
		return data->value;
	}

private:
	CL_Resource res;
	CL_ResourceData_Raw *data;
};

//: Input source interface for 'raw' resource types.
//- !group=Core/Resources!
//- !header=core.h!
class CL_InputSource_Raw : public CL_Raw, public CL_InputSource_Memory
{
public:
	//: Construct input source reading from a 'raw' resource type.
	//param res_id: Resource id of an raw resource to load from.
	//param resources: Resource manager to load resource from.
	CL_InputSource_Raw(const std::string &res_id, CL_ResourceManager *resources)
		: CL_Raw(res_id, resources), CL_InputSource_Memory(std::string((char *) &CL_Raw::get_data()[0], CL_Raw::get_data().size()))
	{
	}
};

#endif
