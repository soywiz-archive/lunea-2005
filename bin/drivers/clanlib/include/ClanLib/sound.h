/*  $Id: sound.h,v 1.14 2003/11/13 13:08:37 grumbel Exp $
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

//: <p>Sound support. If you want sound in your application, you defiantly
//: want to link to this library.</p>
//! Global=Sound

#ifndef header_sound_api
#define header_sound_api

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include "Sound/setupsound.h"
#include "Sound/sound.h"
#include "Sound/soundoutput.h"
#include "Sound/soundformat.h"
#include "Sound/soundprovider.h"
#include "Sound/soundprovider_session.h"
#include "Sound/soundbuffer.h"
#include "Sound/soundbuffer_session.h"
#include "Sound/soundfilter.h"
#include "Sound/cd_drive.h"

#include "Sound/SoundProviders/soundprovider_wave.h"
#include "Sound/SoundProviders/soundprovider_raw.h"
#include "Sound/SoundProviders/soundprovider_recorder.h"

#include "Sound/SoundFilters/echofilter.h"
#include "Sound/SoundFilters/inverse_echofilter.h"
#include "Sound/SoundFilters/fadefilter.h"

#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanSound.lib")
#else
#pragma comment(lib, "clanSoundd.lib")
#endif
#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")
#endif

#endif
