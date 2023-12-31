/*  $Id: vorbis.h,v 1.12 2003/11/13 13:08:37 grumbel Exp $
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

//: <p>Ogg Vorbis playback. With this library, you can play music with the same
//: quality as todays mp3, but with a completely open sound format (mp3 is
//: patented by some greedy companies that want money for each mp3 you use in a
//: commercial product).</p>
//! Global=Vorbis

#ifndef header_vorbis
#define header_vorbis

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include "Vorbis/soundprovider_vorbis.h"
#include "Vorbis/setupvorbis.h"

#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanVorbis.lib")
#else
#pragma comment(lib, "clanVorbisd.lib")
#endif
#pragma comment(lib, "vorbis_static.lib")
#pragma comment(lib, "ogg_static.lib")
#endif

#endif
