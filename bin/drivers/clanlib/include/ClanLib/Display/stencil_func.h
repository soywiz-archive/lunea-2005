/*  $Id: stencil_func.h,v 1.2 2004/01/02 15:42:43 mbn Exp $
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

//! clanDisplay="Display 2D"
//! header=display.h

#ifndef header_stencil_func
#define header_stencil_func

#if _MSC_VER > 1000
#pragma once
#endif

//: Stencil test functions.
//- !group=Display/Display 2D!
//- !header=display.h!
enum CL_StencilFunc
{
	stencil_never,
	stencil_less,
	stencil_lequal,
	stencil_greater,
	stencil_gequal,
	stencil_equal,
	stencil_notequal,
	stencil_always
};

//: Stencil operations
//- !group=Display/Display 2D!
//- !header=display.h!
enum CL_StencilOp
{
	stencil_keep,
	stencil_zero,
	stencil_replace,
	stencil_incr,
	stencil_decr,
	stencil_invert
};

#endif
