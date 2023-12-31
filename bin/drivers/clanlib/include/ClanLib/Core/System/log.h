/*  $Id: log.h,v 1.8 2004/01/09 23:33:09 sphair Exp $
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

#ifndef header_log
#define header_log

#if _MSC_VER > 1000
#pragma once
#endif

#include "../../signals.h"
#include "clanstring.h"

//: Logging interface.
//- !group=Core/System!
//- !header=core.h!
class CL_Log
{
//! Construction:
public:

//! Attributes:
public:
	//: Returns the signal that gets emitted every time a log is posted.
	static CL_Signal_v3<const std::string &, int, const std::string &> &sig_log();

//! Operations:
public:
	//: Posts a log message with severity 0.
	static void log(const std::string &group, const std::string &message);

	//: Posts a log message.
	static void log(const std::string &group, int severity, const std::string &message);

	template<class Param1>
	static void log(const std::string &group, const std::string &format, const Param1 &p1)
	{
		log(group, CL_String::format(format, p1));
	}

	template<class Param1, class Param2>
	static void log(const std::string &group, const std::string &format, const Param1 &p1, const Param2 &p2)
	{
		log(group, CL_String::format(format, p1, p2));
	}

	template<class Param1, class Param2, class Param3>
	static void log(const std::string &group, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3)
	{
		log(group, CL_String::format(format, p1, p2, p3));
	}

	template<class Param1, class Param2, class Param3, class Param4>
	static void log(const std::string &group, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4)
	{
		log(group, CL_String::format(format, p1, p2, p3, p4));
	}

	template<class Param1, class Param2, class Param3, class Param4, class Param5>
	static void log(const std::string &group, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4, const Param5 &p5)
	{
		log(group, CL_String::format(format, p1, p2, p3, p4, p5));
	}

	template<class Param1, class Param2, class Param3, class Param4, class Param5, class Param6>
	static void log(const std::string &group, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4, const Param5 &p5, const Param6 &p6)
	{
		log(group, CL_String::format(format, p1, p2, p3, p4, p5, p6));
	}

	template<class Param1, class Param2, class Param3, class Param4, class Param5, class Param6, class Param7>
	static void log(const std::string &group, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4, const Param5 &p5, const Param6 &p6, const Param7 &p7)
	{
		log(group, CL_String::format(format, p1, p2, p3, p4, p5, p6, p7));
	}

	template<class Param1>
	static void log(const std::string &group, int severity, const std::string &format, const Param1 &p1)
	{
		log(group, severity, CL_String::format(format, p1));
	}

	template<class Param1, class Param2>
	static void log(const std::string &group, int severity, const std::string &format, const Param1 &p1, const Param2 &p2)
	{
		log(group, severity, CL_String::format(format, p1, p2));
	}

	template<class Param1, class Param2, class Param3>
	static void log(const std::string &group, int severity, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3)
	{
		log(group, severity, CL_String::format(format, p1, p2, p3));
	}

	template<class Param1, class Param2, class Param3, class Param4>
	static void log(const std::string &group, int severity, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4)
	{
		log(group, severity, CL_String::format(format, p1, p2, p3, p4));
	}

	template<class Param1, class Param2, class Param3, class Param4, class Param5>
	static void log(const std::string &group, int severity, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4, const Param5 &p5)
	{
		log(group, severity, CL_String::format(format, p1, p2, p3, p4, p5));
	}

	template<class Param1, class Param2, class Param3, class Param4, class Param5, class Param6>
	static void log(const std::string &group, int severity, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4, const Param5 &p5, const Param6 &p6)
	{
		log(group, severity, CL_String::format(format, p1, p2, p3, p4, p5, p6));
	}

	template<class Param1, class Param2, class Param3, class Param4, class Param5, class Param6, class Param7>
	static void log(const std::string &group, int severity, const std::string &format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4, const Param5 &p5, const Param6 &p6, const Param7 &p7)
	{
		log(group, severity, CL_String::format(format, p1, p2, p3, p4, p5, p6, p7));
	}

//! Implementation:
private:
};

#endif
