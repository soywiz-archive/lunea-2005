/*  $Id: sprite_description.h,v 1.28 2004/04/20 13:36:27 sphair Exp $
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

#ifndef header_sprite_description
#define header_sprite_description

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include <string>
#include <map>
#include <list>

#include "../Core/Math/rect.h"
#include "surface.h"

class CL_ResourceManager;
class CL_PixelBuffer;
class CL_SpriteDescription_Generic;

//: This class contains everything to construct a sprite - its data, default settings etc.
//- !group=Display/Sprites!
//- !header=display.h!
//- <p>CL_SpriteDescription is used by CL_Sprite to construct itself based
//- on the description. The description class give a big flexibility
//- creating a sprite, individual frames can come from different image
//- sources, or be cut out from an image source using various different
//- techniques.</p>
class CL_SpriteDescription
{ 
//! Construction:
public:
	//: Constructs a sprite description.
	//param resource_id: Resource name of a sprite description resource.
	//param resources: Resource manager used to load resource.
	CL_SpriteDescription(const std::string &resource_id, CL_ResourceManager *resources);

	CL_SpriteDescription();

	CL_SpriteDescription(const CL_SpriteDescription &copy);

	~CL_SpriteDescription();

//! Attributes:
public:
	//: CL_PixelBuffer *provider, CL_Rect position.
	typedef std::pair<CL_PixelBuffer *, CL_Rect> FramePair;

	//: Returns a list over all available frames.
	const std::list<FramePair> &get_frames() const;

	//: Returns the surface flag to be used.
	int get_surface_flag() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_SpriteDescription &operator =(const CL_SpriteDescription &copy);

	//: Sets what surface flag CL_Sprite should use for its surfaces.
	void set_surface_flag(int flag);

	//: Adds a single image.
	//param provider: Image source.
	//param delete_provider: If true, deletes provider when sprite description is destroyed.
	void add_frame(CL_PixelBuffer *provider, bool delete_provider = false);

	//: Adds images formed in a grid.
	//- <p>This function will cut out a grid of frames from one image.</p>
	//param provider: Image source.
	//param xpos, ypos: Position of where image grid starts.
	//param width, height: Size of a frame in the grid.
	//param xarray, yarray: Number of columns and rows in grid.
	//param array_skipframes: Number of frames to skip at last gridline.
	//param xspacing, yspacing: Pixel interspacing between grid frames.
	//param delete_provider: If true, deletes provider when sprite description is destroyed.
	void add_gridclipped_frames(CL_PixelBuffer *provider, int xpos, int ypos, int width, int height, int xarray = 1, int yarray = 1, int array_skipframes = 0, int xspacing = 0, int yspacing = 0, bool delete_provider = false);

	//: Adds images separated with pure alpha (within trans_limit).
	//- <p>The alpha clipper will cut out frames from an image based on
	//- the transparency in the picture. It first determines the height
	//- of a row by searching for the first line that it considers
	//- completely transparent. Then it finds the width of each frame on
	//- this line by looking for columns that are completely transparency.</p>
	//param provider: Image source.
	//param xpos, ypos: Upper left position where alpha cutting should begin.
	//param trans_limit: Amount of non-transparent alpha allowed before a pixel is not considered transparent.
	//param delete_provider: If true, deletes provider when sprite description is destroyed.
	void add_alphaclipped_frames(CL_PixelBuffer *provider, int xpos = 0, int ypos = 0, float trans_limit = 0.05f, bool delete_provider = false);

	//: Adds images separated with pure alpha (within trans_limit).
	//- <p>The alpha clipper will cut out frames from an image based on
	//- the transparency in the picture. It scans the lines horizontally
	//- from top to bottom. As soon as a non-transarent pixel is discovered,
	//- the clipper finds the bounding box for that region and then moves on.</p>
	//param provider: Image source.
	//param xpos, ypos: Upper left position where alpha cutting should begin.
	//param trans_limit: Amount of non-transparent alpha allowed before a pixel is not considered transparent.
	//param delete_provider: If true, deletes provider when sprite description is destroyed.
	void add_alphaclipped_frames_free(CL_PixelBuffer *provider, int xpos = 0, int ypos = 0, float trans_limit = 0.05f, bool delete_provider = false);

	//: Adds images separated with palette-colours defining the boundaries.
	//param provider: Image source.
	//param xpos, ypos: Upper left position where cutting should begin.
	//param delete_provider: If true, deletes provider when sprite description is destroyed.
	void add_paletteclipped_frames(CL_PixelBuffer *provider, int xpos = 0, int ypos = 0, bool delete_provider = false);
	
//! Implementation:
private:
	//: SpriteDescription implementation.
	CL_SpriteDescription_Generic *impl;
};

#endif


