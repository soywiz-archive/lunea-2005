/*  $Id: application.h,v 1.7 2003/10/14 15:52:10 mbn Exp $
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

//: <p>Application bootstrapping library. When booting your application,
//: you can either use the low level, platform dependent approach in clanCore,
//: or you can use the CL_ClanApplication interface in clanApp.</p>
//! Global=App

#ifndef header_application
#define header_application

#if _MSC_VER > 1000
#pragma once
#endif

#include "Application/clanapp.h"

#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanApp.lib")
#else
#pragma comment(lib, "clanAppd.lib")
#endif
#endif

#endif
