/*  $Id: datatypes.h,v 1.6 2003/12/29 14:59:24 mbn Exp $
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

//! clanCore="I/O Data"
//! header=core.h

#ifndef header_iotypes
#define header_iotypes

#if _MSC_VER > 1000
#pragma once
#endif

#if defined(WIN32) && (defined(__MINGW32__) == 0)
typedef __int8             cl_int8;
typedef unsigned __int8    cl_uint8;
typedef __int16            cl_int16;
typedef unsigned __int16   cl_uint16;
typedef __int32            cl_int32;
typedef unsigned __int32   cl_uint32;
typedef __int64            cl_int64;
typedef unsigned __int64   cl_uint64;
#else
typedef char               cl_int8;
typedef unsigned char      cl_uint8;
typedef short              cl_int16;
typedef unsigned short     cl_uint16;
typedef int                cl_int32;
typedef unsigned int       cl_uint32;
typedef long long          cl_int64;
typedef unsigned long long cl_uint64;
#endif

#endif
