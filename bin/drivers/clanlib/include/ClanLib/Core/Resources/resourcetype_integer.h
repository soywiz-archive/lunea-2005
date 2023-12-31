/*  $Id: resourcetype_integer.h,v 1.18 2004/02/17 21:28:14 mbn Exp $
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

#ifndef header_resourcetype_integer
#define header_resourcetype_integer

#if _MSC_VER > 1000
#pragma once
#endif

#include "resourcedata.h"
#include "resource_manager.h"
#include "resource.h"
#include <string>
#include "../System/error.h"
#include "../System/error.h"

//: Resource Data object for an 'integer' resource type.
//- !group=Core/Resources!
//- !header=core.h!
class CL_ResourceData_Integer : public CL_ResourceData
{
//! Construction:
public:
	//: Resource Data Integer Constructor.
	CL_ResourceData_Integer(class CL_Resource &resource);

//! Attributes:
public:
	//: Integer Value.
	int value;
};

//: Integer resource accessor class.
//- !group=Core/Resources!
//- !header=core.h!
class CL_Integer
{
//! Construction:
public:
	//: Constructs an integer.
	//param res_id: Resource id of an integer resource to be constructed from.
	//param resources: Resource manager to load resource from.
	//param def_value: Default value to use if resource is not found.
	CL_Integer(const std::string &res_id, CL_ResourceManager *resources)
	{
		CL_Resource res = resources->get_resource(res_id);
		res.load();
		CL_ResourceData_Integer *data = (CL_ResourceData_Integer *) res.get_data("integer");
		value = data->value;
		res.unload();
	}

	CL_Integer(const std::string &res_id, CL_ResourceManager *resources, int def_value)
	{
		try
		{
			CL_Resource res = resources->get_resource(res_id);
			res.load();
			CL_ResourceData_Integer *data = (CL_ResourceData_Integer *) res.get_data("integer");
			value = data->value;
			res.unload();
		}
		catch (CL_Error err)
		{
			value = def_value;
		}
	}

//! Operators:
	//: Converts a CL_Integer to an integer.
	operator int() const
	{
		return value;
	}

	//: Loads a boolean from a resource.
	//param res_id: Resource to load boolean from.
	//param resources: Resource manager used to load boolean.
	//param def_value: Default value if resource is not found.
	static int load( const std::string &res_id, CL_ResourceManager *resources )
	{
		return (int) CL_Integer(res_id, resources );
	}

	static int load( const std::string &res_id, CL_ResourceManager *resources, bool def_value )
	{
		return (int) CL_Integer(res_id, resources, def_value );
	}


private:
	int value;
};

#endif
