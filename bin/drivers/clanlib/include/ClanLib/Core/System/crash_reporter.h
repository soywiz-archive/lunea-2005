/*  $Id: crash_reporter.h,v 1.5 2004/02/01 03:07:16 mbn Exp $
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

//! clanCore="System"
//! header=core.h

#ifndef header_crash_reporter
#define header_crash_reporter

#if _MSC_VER > 1000
#pragma once
#endif

#include "../../signals.h"
#include "call_stack.h"
#include "sharedptr.h"

class CL_CrashReporter_Generic;

//: Crash reporting tool.
//- !group=Core/System!
//- !header=core.h!
//- <p>Constructing an instance of this class in a thread will cause any fatal errors
//- (ie. segmentation faults) to be caught and handled by the crash reporter. It
//- will then dump the callstack to file and then afterwards emit sig_crash.</p>
class CL_CrashReporter
{
//! Construction:
public:
	CL_CrashReporter();

	~CL_CrashReporter();

//! Attributes:
public:
	//: Returns the flag indicating if it will dump the callstack to file.
	static bool get_dump_to_file();

	//: If enabled, will dump the callstack to file before emitting sig_crash.
	static void set_dump_to_file(bool enable);

//! Operations:
public:
	//: Signal emitted when fatal errors are caught.
	static CL_Signal_v2<std::string, CL_CallStack> &sig_crash();

//! Implementation:
private:
	CL_SharedPtr<CL_CrashReporter_Generic> impl;
};

#endif
