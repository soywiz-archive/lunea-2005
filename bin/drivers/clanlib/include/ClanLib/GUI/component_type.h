/*  $Id: component_type.h,v 1.34 2004/01/02 15:42:43 mbn Exp $
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

//! clanGUI="Framework"
//! header=gui.h

#ifndef header_component_type
#define header_component_type

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/System/clanstring.h"
#include <set>
#include <string>
#include <map>

class CL_Component;
class CL_StyleManager;
class CL_ComponentType_Generic;

//: Component Type.
//- !group=GUI/Framework!
//- !header=gui.h!
class CL_ComponentType
{
//! Construction:
public:
	//: Component Type Constructor
	CL_ComponentType();

	//: Component Type Destructor
	virtual ~CL_ComponentType();

//! Enums:
public:
	enum EDatatype
	{
		STRING,
		BOOL,
		NUMBER
	};

//! Attributes:
public:
	struct SOptionType
	{
		EDatatype type;

		std::string default_value;
	};

	//: List of known component types.
	static std::map<std::string, CL_ComponentType *> component_types;

	//: Options for component type.
	const std::map<std::string, SOptionType> &get_options() const;

	//: Has option
	bool has_option(const std::string &option_name) const;

	EDatatype get_data_type(const std::string &option_name) const;

	std::string get_default_value(const std::string &option_name) const;

	const std::string &get_class_name() const;

	static EDatatype get_data_type(const std::string &type, const std::string &option_name);

	static std::string get_default_value(const std::string &type, const std::string &option_name);

	static const std::string &get_class_name(const std::string &type);

//! Operations:
public:
	//: Sets an option's datatype and default value.
	void set_option(const std::string &name, EDatatype datatype, const std::string &value);

	//: Sets the class name (ie "CL_Button") of a component type.
	void set_class_name(const std::string &class_name);

	//: Creates a component of type 'component_type_name'.
	//- <p>If no such component type exists, a CL_Error is thrown. The method
	//- invokes the specific component type's
	//- virtual 'create_component' method with the passed arguments.</p>
	static CL_Component *create_component(
		const std::string &type,
		CL_Component *parent,
		CL_StyleManager *style);

	//: Create component.
	virtual CL_Component *create_component(
		CL_Component *parent,
		CL_StyleManager *style) = 0;

// !Implementation:
private:
	CL_ComponentType_Generic *impl;
};

#endif
