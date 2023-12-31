/*  $Id: resourcetype_float.h,v 1.1 2004/04/07 07:45:39 sphair Exp $
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

#ifndef header_resourcetype_float
#define header_resourcetype_float

#if _MSC_VER > 1000
#pragma once
#endif

#include "resourcedata.h"
#include "resource_manager.h"
#include "resource.h"
#include <string>
#include "../System/error.h"
#include "../System/error.h"

//: Resource Data object for an 'float' resource type.
//- !group=Core/Resources!
//- !header=core.h!
class CL_ResourceData_Float : public CL_ResourceData
{
//! Construction:
public:
	//: Resource Data Float Constructor.
	CL_ResourceData_Float(class CL_Resource &resource);

//! Attributes:
public:
	//: Float Value.
	float value;
};

//: r resource accessor class.
//- !group=Core/Resources!
//- !header=core.h!
class CL_Float
{
//! Construction:
public:
	//: Constructs a float
	//param res_id: Resource id of a float resource to be constructed from.
	//param resources: Resource manager to load resource from.
	//param def_value: Default value to use if resource is not found.
	CL_Float(const std::string &res_id, CL_ResourceManager *resources)
	{
		CL_Resource res = resources->get_resource(res_id);
		res.load();
		CL_ResourceData_Float *data = (CL_ResourceData_Float *) res.get_data("float");
		value = data->value;
		res.unload();
	}

	CL_Float(const std::string &res_id, CL_ResourceManager *resources, float def_value)
	{
		try
		{
			CL_Resource res = resources->get_resource(res_id);
			res.load();
			CL_ResourceData_Float *data = (CL_ResourceData_Float *) res.get_data("float");
			value = data->value;
			res.unload();
		}
		catch (CL_Error err)
		{
			value = def_value;
		}
	}

//! Operators:
	//: Converts a CL_Float to a float.
	operator float() const
	{
		return value;
	}

private:
	float value;
};

#endif
