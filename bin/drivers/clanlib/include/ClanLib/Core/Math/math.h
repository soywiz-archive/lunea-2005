/*  $Id: math.h,v 1.6 2003/10/14 15:52:10 mbn Exp $
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

#ifndef header_math
#define header_math

#if _MSC_VER > 1000
#pragma once
#endif

#include <cmath>
#include <math.h>

#ifndef PI
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795	// maybe more accuracy than needed ;-)
#endif
#define PI M_PI
#endif

#endif
