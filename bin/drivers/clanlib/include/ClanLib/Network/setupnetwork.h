/*  $Id: setupnetwork.h,v 1.6 2004/03/13 23:04:12 mbn Exp $
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

//! clanNetwork="System"
//! header=network.h

#ifndef header_setupnetwork
#define header_setupnetwork

#if _MSC_VER > 1000
#pragma once
#endif

//: Initialization class for clanNetwork.
//- !group=Network/System!
//- !header=network.h!
class CL_SetupNetwork
{
//! Construction:
public:
	//: Initializes clanNetwork.
	//- <p>Constructing a CL_SetupNetwork object is equalent to calling CL_SetupNetwork::init().</p>
	//- <p>When the CL_SetupNetwork instance is destroyed, CL_SetupNetwork::deinit() is called.</p>
	CL_SetupNetwork(bool register_resources_only = false);

	~CL_SetupNetwork();

//! Operations:
public:
	//: Initialize network.
	static void init(bool register_resources_only = false);

	//: Deinitialize network.
	static void deinit();
};

#endif
