/*  $Id: core_iostream.h,v 1.1 2004/01/17 01:26:14 grumbel Exp $
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

#ifndef header_core_iostream
#define header_core_iostream

#include <iosfwd>

class CL_Rect;
class CL_Rectf;
class CL_Point;
class CL_Pointf;
class CL_Size;
class CL_Sizef;

std::ostream& operator<<(std::ostream& s, const CL_Rect& rect);
std::ostream& operator<<(std::ostream& s, const CL_Rectf& rect);
std::ostream& operator<<(std::ostream& s, const CL_Point& point);
std::ostream& operator<<(std::ostream& s, const CL_Pointf& point);
std::ostream& operator<<(std::ostream& s, const CL_Size& size);
std::ostream& operator<<(std::ostream& s, const CL_Sizef& size);

#endif
