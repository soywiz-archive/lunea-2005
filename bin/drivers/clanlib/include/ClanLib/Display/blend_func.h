/*  $Id: blend_func.h,v 1.8 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_blend_func
#define header_blend_func

#if _MSC_VER > 1000
#pragma once
#endif

//: Blending functions.
//- !group=Display/Display 2D!
//- !header=display.h!
enum CL_BlendFunc
{
	blend_zero,                     // source or destination (0, 0, 0, 0)
	blend_one,                      // source or destination (1, 1, 1, 1)
	blend_dest_color,               // source                (Rd, Gd, Bd, Ad)
	blend_src_color,                // destination           (Rs, Gs, Bs, As)
	blend_one_minus_dest_color,     // source                (1, 1, 1, 1) - (Rd, Gd, Bd, Ad)
	blend_one_minus_src_color,      // destination           (1, 1, 1, 1) - (Rs, Gs, Bs, As)
	blend_src_alpha,                // source or destination (As, As, As, As)
	blend_one_minus_src_alpha,      // source or destination (1, 1, 1, 1) - (As, As, As, As)
	blend_dst_alpha,                // source or destination (Ad, Ad, Ad, Ad)
	blend_one_minus_dest_alpha,     // source or destination (1, 1, 1, 1) - (Ad, Ad, Ad, Ad)
	blend_src_alpha_saturate,       // source                (f, f, f, 1) - f = min(As, 1 - Ad)
	blend_constant_color,           // source or destination (Rc, Gc, Bc, Ac)
	blend_one_minus_constant_color, // source or destination (1, 1, 1, 1) - (Rc, Gc, Bc, Ac)
	blend_constant_alpha,           // source or destination (Ac, Ac, Ac, Ac)
	blend_one_minus_constant_alpha  // source or destination (1, 1, 1, 1) - (Ac, Ac, Ac, Ac)
};

#endif
