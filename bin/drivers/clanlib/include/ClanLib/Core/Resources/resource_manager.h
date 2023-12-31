/*  $Id: resource_manager.h,v 1.35 2004/02/01 01:54:16 mbn Exp $
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

#ifndef header_resource_manager
#define header_resource_manager

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"
#include "../../signals.h"
#include <list>
#include <string>

class CL_Resource;
class CL_InputSourceProvider;
class CL_ResourceManager_Generic;

class CL_ResourceManager
//: The ClanLib resource manager.
//- !group=Core/Resources!
//- !header=core.h!
//- <p>The resource manager is used to retrieve resources from a given
//- resource source.</p>
//-
//- <p>This can either be a resource script file (used as input to the
//- datafile compiler), or a datafile with all the resources included into
//- one large gzipped resource file.</p>
//-
//- <p>To speedup loading of resources in a game, you can load entire sections
//- of resources at once. When a resource in the section is requested, it is
//- returned instantly without having to access the disk. This is especially
//- useful to make sure all the game resources are loaded before the game is
//- started.</p>
//-
//- <p>Resources are normally not retrieved using the get_resource() function.
//- Instead, you should load the resource using the appropiate resource type
//- class. For instance, a surface is easiest loaded like this:</p>
//-
//- <pre>
//- CL_ResourceManager res_manager("my_datafile.dat", true);
//- CL_Surface my_surface("my_surface", &res_manager);
//- </pre>
//-
//- <p>Getting the same resource twice won't create a new instance of the
//- resource; they are reference counted.</p>
{
//! Construction:
public:
	//: Resource Manager constructor.
	//param config_file: The name of the file in which the resources are defined.
	//param provider: The optional inputprovider in which, the resource file is stored.
	//param delete_inputsource_provider: If true, deletes the provider when CL_ResourceManager is destroyed.
	CL_ResourceManager(
		const std::string &config_file,
		CL_InputSourceProvider *provider = 0,
		bool delete_inputsource_provider = false);

	CL_ResourceManager(const CL_ResourceManager &copy);

	CL_ResourceManager();

	//: Resource Manager destructor.
	~CL_ResourceManager();

//! Attributes:
public:
	//: Returns true if a resource exists.
	bool exists(const std::string &res_id);
	
	//: Returns a pointer to the CL_Resource representing the given resource.
	CL_Resource &get_resource(const std::string &res_id);

	//: Returns a list of all resources available.
	//return: The list of resources available, in the form [section/subsection/.../]resourcename.
	std::list<std::string> get_all_resources();

	//: Returns a list of all resources available matching a given section. 
	//return: The list of resources available, in the form [section/subsection/.../]resourcename.
	std::list<std::string> get_all_resources(const std::string &section_name);

	//: Returns a list of all resource sections available.
	//return: The list of resources available, in the form [section/subsection/.../].
	std::list<std::string> get_all_sections();

	//: Returns a list of all resources available matching a given type. 
	//return: The list of resources available.
	std::list<std::string> get_resources_of_type(const std::string &type_id);

	//: Returns a list of all resources available matching a given type in a given section. 
	//return: The list of resources available.
	std::list<std::string> get_resources_of_type(const std::string &type_id, const std::string &section_name);

	//: Returns a pointer to the input source provider, in which all resources are stored.
	//- <p>This can be a file provider or a datafile provider depending
	//- on method used to load the script file.</p>
	//return: Pointer to inputsourceprovider containing resource data.
	CL_InputSourceProvider *get_resource_provider() const;

//! Signals:
public:
	//: Signal invoked when a resource is added during loading of a resource file.
	static CL_Signal_v1<CL_Resource &> &sig_resource_added();

//! Operations:
public:
	//: Returns true resource managers handles the same object.
	bool operator == (const CL_ResourceManager &other) const;

	//: Add resources from an other resource manager.
	void add_resources(const CL_ResourceManager &additional_resources);

	//: Remove resources from an other resource manager.
	void remove_resources(const CL_ResourceManager &additional_resources);

	//: Loads all resources into memory.
	void load_all();

	//: Unloads all resources from memory.
	void unload_all();

	//: Loads all resources in a given section into memory.
	void load_section(const std::string &section_name);

	//: Unloads all resources in a given section into memory.
	void unload_section(const std::string &section_name);

//! Implementation:
private:
	CL_ResourceManager(const CL_SharedPtr<CL_ResourceManager_Generic> &impl);

	//: Pointer to the implementation.
	CL_SharedPtr<CL_ResourceManager_Generic> impl;

	friend class CL_Resource;
};
#endif
