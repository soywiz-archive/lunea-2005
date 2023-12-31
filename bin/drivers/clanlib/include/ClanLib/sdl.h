/*  $Id: sdl.h,v 1.3 2003/11/11 11:23:41 mbn Exp $
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

//: <p>ClanLib SDL support. Contains SDL binding code and SDL integration
//: frameworks.</p>
//! Global=SDL

#ifndef header_sdl
#define header_sdl

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef WIN32
	#pragma warning (disable:4786)
	#include <windows.h>
#endif

#include "SDL/setupsdl.h"

#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanSDL.lib")
#else
#pragma comment(lib, "clanSDLd.lib")
#endif
#pragma comment(lib, "SDL.lib")
#endif

#endif
