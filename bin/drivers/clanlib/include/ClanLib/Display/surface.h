/*  $Id: surface.h,v 1.57 2004/05/06 12:36:01 grumbel Exp $
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

#ifndef header_surface
#define header_surface

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include "blend_func.h"
#include "../Core/Math/origin.h"
#include "color.h"
#include <string>

#include "../Core/Resources/resource.h"

class CL_PixelBuffer;
class CL_GraphicContext;
class CL_Point;
class CL_Rect;
class CL_ResourceManager;
class CL_Sprite;
class CL_Surface_Generic;
class CL_Canvas;

//: Drawing parameters (level 1) for stateless draw of CL_Surface.
struct CL_Surface_DrawParams1
{
	int srcX[4];
	int srcY[4];
	double destX[4];
	double destY[4];
	double destZ;
	double red[4];
	double green[4];
	double blue[4];
	double alpha[4];
	CL_BlendFunc blend_src;
	CL_BlendFunc blend_dest;
};

//: Drawing parameters (level 2) for stateless draw of CL_Surface.
struct CL_Surface_DrawParams2
{
	int srcX;
	int srcY;
	int srcWidth;
	int srcHeight;
	double destX;
	double destY;
	double destZ;
	double red;
	double green;
	double blue;
	double alpha;
	CL_BlendFunc blend_src;
	CL_BlendFunc blend_dest;
	double scale_x;
	double scale_y;
	CL_Origin translate_origin;
	int translate_x;
	int translate_y;
	double rotate_angle;
	double rotate_pitch;
	double rotate_yaw;
	CL_Origin rotate_origin;
	int rotate_x;
	int rotate_y;
};

//: Construct hardware accelerated (where available) 2D surface.
//- !group=Display/Display 2D!
//- !header=display.h!
// TODO: Add flip_vertical, flip_horizontal ?
class CL_Surface
{
//! Enums:
public:
	enum Flag
	{
		flag_none = 0,

		//: pixelbuffer will be kept around after creation, to be able
		//: to retrive it with get_pixeldata() without conversion loss.
		flag_keep_pixelbuffer = 1,

		//: surface will be forced to use 16bit even on 32bit displays.
		flag_force_16bit = 2
	};

//! Construction:
public:
	//: Constructs a surface.
	//param provider: Image that surface will use.
	//param delete_provider: If true, will delete provider after it has copied its image data.
	//param flag: Flags which affects how surface will be created.
	//param filename: Name of an image file to load image data from.
	CL_Surface();

	CL_Surface(
		CL_PixelBuffer *provider,
		bool delete_provider = false,
		int flag = flag_none);

	CL_Surface(
		const std::string &resource_id,
		CL_ResourceManager *manager);

	CL_Surface(const std::string &filename, int flag = flag_none);

	CL_Surface(const CL_Surface &copy);

	virtual ~CL_Surface();

//! Attributes:
public:
	//: Returns the width.
	int get_width() const;
	
	//: Returns the height.
	int get_height() const;
	
	//: Returns current angle in degrees.
	float get_angle() const;

	//: Returns scale for x and y.
	//- <p> 1.0f is normal scale, 2.0f is twice the size, etc. </p>
	void get_scale(float &x, float &y) const;

	//: Returns current alpha.
	//- <p> Alpha 0.0f is full transparency, and 1.0f is full visibility (solid). </p>
	float get_alpha() const;

	//: Returns current color.
	//- <p> Alpha 0.0f is full transparency, and 1.0f is full visibility (solid). </p>
	void get_color(float &red, float &green, float &blue, float &alpha) const;
	CL_Color get_color() const {float r,g,b,a; get_color(r,g,b,a); return CL_Color(int(r*255.0f),int(g*255.0f),int(b*255.0f),int(a*255.0f));}
	
	//: Returns blending functions.
	void get_blend_func(CL_BlendFunc &src, CL_BlendFunc &dest) const;

	//: Returns translation hotspot.
	void get_alignment(CL_Origin &origin, int &x, int &y) const;

	//: Returns rotation hotspot.
	void get_rotation_hotspot(CL_Origin &origin, int &x, int &y) const;
	
	//: Returns a pixelbuffer object for accessing surface data.
	CL_PixelBuffer get_pixeldata() const;
	
	//: Resource owning this surface, if any.
	CL_Resource resource;

//! Operations:
public:
	//: Copy assignment operator.
	CL_Surface &operator =(const CL_Surface &copy);

	//: Return true if the CL_Surface is valid and useable
	operator bool () const;

	//: Uploads pixel data to surface.
	//!param pos, x, y: Position on surface where pixel data should be put.
	//!param src_rect: Part of pixelbuffer that should be uploaded.
	//!param pixeldata: CL_PixelBuffer containing the image to be uploaded.
	void set_pixeldata(CL_PixelBuffer &pixeldata);
	
	void set_pixeldata(int x, int y, CL_PixelBuffer &pixeldata);
	
	void set_pixeldata(const CL_Point &pos, CL_PixelBuffer &pixeldata);
	
	void set_pixeldata(const CL_Point &pos, const CL_Rect &src_rect, CL_PixelBuffer &pixeldata);

	//: Stateful draw surface on graphic context.
	//- <p>These drawing functions will draw the surface on the graphic context, using the attributes on CL_Surface.
	//- Attributes such as scaling, translate hotspot, rotate hotspot, blend functions, color will be used when
	//- drawing the surface.</p>
	//param x, y: Anchor position of where to render surface. Actual rendering position depends on the anchor and the alignment mode.
	//param context: Graphic context on which to render upon. If null, will use CL_Display's current graphic context.
	//param dest: Rectangle to draw surface in.
	//param src: Rectangle specifying the sub section of a surface to render.
	void draw(
		int x = 0,
		int y = 0,
		CL_GraphicContext *context = 0);

	void draw(
		const CL_Rect &dest,
		CL_GraphicContext *context = 0);

	void draw(
		const CL_Rect &src,
		const CL_Rect &dest,
		CL_GraphicContext *context = 0);

	//: Stateless draw surface on graphic context.
	//- <p>Stateless drawing functions will not use any of the state attributes on CL_Surface. The state attributes
	//- on CL_Surface are parameters such as scaling, hotspots, blending functions and color. Instead the drawing
	//- functions take all the parameters it need to perform the render.</p>
	//param srcX, srcY, srcWidth, srcHeight: Source rectangle for the surface.
	//param srcX[4], srcY[4]: Four vertex points used as the source rectangle for the render.
	//param destX, destY: Destination origin point for render.
	//param destZ: Depth value for zbuffer when rendering.
	//param red[4], green[4], blue[4], alpha[4]: Color for each corner of rectangle.
	//param red, green, blue, alpha: Color for entire rectangle.
	//param blend_src: Source blend function.
	//param blend_dest: Destination blend function.
	//param scale_x, scale_y: Scale values for render.
	//param translate_origin: Alignment origin.
	//param translate_x, translate_y: Translate relative to alignment origin.
	//param rotate_angle: Angle in degrees to rotate the surface in the X-Y direction.
	//param rotate_pitch: Angle in degrees to rotate the surface in the Y-Z direction.
	//param rotate_yaw: Angle in degrees to rotate the surface in the X-Z direction.
	//param rotate_origin: Rotation origin.
	//param rotate_x, rotate_y: Rotation hotspot relative to rotation origin.
	//param context: Graphic context on which to render upon. If null, will use CL_Display's current graphic context.
	void draw(
		CL_Surface_DrawParams1 *params1,
		CL_GraphicContext *context = 0);

	void draw(
		CL_Surface_DrawParams2 *params2,
		CL_GraphicContext *context = 0);

	//: Set absolute rotation angle in degrees.
	void set_angle(float angle);
	
	//: Set absolute rotation pitch angle in degrees.
	void set_angle_pitch(float angle);
	
	//: Set absolute rotation yaw angle in degrees.
	void set_angle_yaw(float angle);

	//: Add angle in degrees to current angle.
	void rotate(float angle);
	
	//: Add angle in degrees to current pitch angle.
	void rotate_pitch(float angle);
	
	//: Add angle in degrees to current yaw angle.
	void rotate_yaw(float angle);

	//: Set scale for x and y directions individually.
	//- <p> 1.0f is normal scale, 2.0f is twice the size, etc. </p>
	void set_scale(float x, float y);

	//: Sets transparency.
	//- <p> Alpha 0.0f is full transparency, and 1.0f is full visibility (solid). </p>
	void set_alpha(float alpha);

	//: Sets the color.
	//- <p> Alpha 0.0f is full transparency, and 1.0f is full visibility (solid). </p>
	void set_color(float r, float g, float b, float a = 1.0f);
	void set_color(const CL_Color& c) {set_color(float(c.get_red())/255.0f,float(c.get_green())/255.0f,float(c.get_blue())/255.0f,float(c.get_alpha())/255.0f);}
	
	//: Sets blending functions.
	void set_blend_func(CL_BlendFunc src, CL_BlendFunc dest);

	//: Sets translation hotspot.
	void set_alignment(CL_Origin origin, int x = 0, int y = 0);

	//: Sets rotation hotspot.
	void set_rotation_hotspot(CL_Origin origin, int x = 0, int y = 0);

// Implementation:
protected:
	CL_Surface_Generic *impl;

	friend class CL_Canvas;
};

#endif
