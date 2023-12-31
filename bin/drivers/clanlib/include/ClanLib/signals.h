/*  $Id: signals.h,v 1.14 2004/01/28 01:17:37 mbn Exp $
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

//: <p>ClanLib signal system. Signals is an other word for callback functions. A
//: C++ signal library provides a typecast clean interface to allow for
//: callbacks to be called, without doing nasty pointer casts all the time. You
//: can use this library totally independent of the rest of clanlib, if you
//: want (as soon as you've learned about signals, you will love them - trust me).</p>
//! Global=Signal

#ifndef header_signals
#define header_signals

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include "Signals/slot.h"
#include "Signals/signal_v0.h"
#include "Signals/signal_v1.h"
#include "Signals/signal_v2.h"
#include "Signals/signal_v3.h"
#include "Signals/signal_v4.h"
#include "Signals/signal_v5.h"
#include "Signals/slotbuffer_v0.h"
#include "Signals/slotbuffer_v1.h"
#include "Signals/slot_container.h"

#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanSignals.lib")
#else
#pragma comment(lib, "clanSignalsd.lib")
#endif
#endif

#endif
