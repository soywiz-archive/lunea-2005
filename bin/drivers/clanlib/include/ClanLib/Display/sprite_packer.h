/*  $Id: sprite_packer.h,v 1.18 2004/01/02 15:42:43 mbn Exp $
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

//! clanDisplay="Sprites"
//! header=display.h

#ifndef header_sprite_packer
#define header_sprite_packer

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include "surface.h"
#include "../Core/Math/size.h"
#include "../Core/Math/rect.h"

#include <vector>

class CL_SpriteDescription;
class CL_SpritePacker_Generic;

//: Packs sprite into one or more textures.
//- !group=Display/Sprites!
//- !header=display.h!
class CL_SpritePacker
{ 
//! Construction:
public:
	//: Constructs a CL_SpritePacker.
	CL_SpritePacker(const CL_SpriteDescription &description);

	~CL_SpritePacker();

//! Attributes:
public:
	//: Returns a list over all the textures needed for the packed-frames.
	//- <p> The get_frames() method returns a list consisting of many TexturePair, where each pair
	//- has an index into this list. </p>
	const std::vector<CL_Size> &get_texture_sizes() const;

	typedef std::pair<int, CL_Rect> TexturePair;	// int texture, CL_Rect frame_position
	//: Returns a list over all frames - which texture it is packed in and where within the
	//: texture it is located.
	//- <p> This list is arranged exactly the same order as the spritedescription frames. </p>
	const std::list<TexturePair> &get_frames() const;

//! Operations:
public:
	//: Packs all frames into one or more textures.
	//: Returns false if it was unable to pack all frames.
	bool pack(
		int max_width = 256, int max_height = 256,
		int min_width = 16, int min_height = 16,
		int max_textures = -1);

//! Implementation:
private:
	// Disallow copy construction.
	CL_SpritePacker(const CL_SpritePacker &copy);

	//: Disallow copy assignment.
	CL_SpritePacker &operator =(const CL_SpritePacker &copy);

	//: CL_SpritePacker implementation.
	CL_SpritePacker_Generic *impl;
};

#endif


