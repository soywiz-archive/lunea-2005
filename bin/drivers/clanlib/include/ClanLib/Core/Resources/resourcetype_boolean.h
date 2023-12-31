/*  $Id: resourcetype_boolean.h,v 1.19 2004/02/17 21:28:14 mbn Exp $
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

#ifndef header_resourcetype_boolean
#define header_resourcetype_boolean

#if _MSC_VER > 1000
#pragma once
#endif

#include "resourcedata.h"
#include "resource_manager.h"
#include "resource.h"
#include <string>
#include "../System/error.h"
#include "../System/error.h"

//: Resource Data object for a 'boolean' resource type.
//- !group=Core/Resources!
//- !header=core.h!
class CL_ResourceData_Boolean : public CL_ResourceData
{
//! Construction:
public:
	//: Resource Data Boolean Constructor.
	CL_ResourceData_Boolean(class CL_Resource &resource);

//! Attributes:
public:
	//: Value
	bool value;
};

//: Boolean resource accessor class.
//- !group=Core/Resources!
//- !header=core.h!
class CL_Boolean
{
//! Construction:
public:
	//: Constructs a boolean.
	//param res_id: Resource id of a boolean resource to be constructed from.
	//param resources: Resource manager to load resource from.
	//param def_value: Default value to use if resource is not found.
	CL_Boolean(const std::string &res_id, CL_ResourceManager *resources)
	{
		CL_Resource res = resources->get_resource(res_id);
		res.load();
		CL_ResourceData_Boolean *data = (CL_ResourceData_Boolean *) res.get_data("boolean");
		value = data->value;
		res.unload();
	}

	CL_Boolean(const std::string &res_id, CL_ResourceManager *resources, bool def_value)
	{
		try
		{
			CL_Resource res = resources->get_resource(res_id);
			res.load();
			CL_ResourceData_Boolean *data = (CL_ResourceData_Boolean *) res.get_data("boolean");
			value = data->value;
			res.unload();
		}
		catch (CL_Error err)
		{
			value = def_value;
		}
	}

//! Operators:
	//: Converts a CL_Boolean to a bool.
	operator bool() const
	{
		return value;
	}

	//: Loads a boolean from a resource.
	//param res_id: Resource to load boolean from.
	//param resources: Resource manager used to load boolean.
	//param def_value: Default value if resource is not found.
	static bool load( const std::string &res_id, CL_ResourceManager *resources )
	{
		return (bool) CL_Boolean(res_id, resources );
	}

	static bool load( const std::string &res_id, CL_ResourceManager *resources, bool def_value )
	{
		return (bool) CL_Boolean(res_id, resources, def_value );
	}

//! Implementation:
private:
	bool value;
};

#endif
