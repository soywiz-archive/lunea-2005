#ifndef _SPHRITELIB_TEXTUREGL_H_
#define _SPHRITELIB_TEXTUREGL_H_

#include <ClanLib/gl.h>

struct RGBA
{
	float rgba[4];
};

class Texture : public CL_Texture
{
// Construction:
public:
	Texture() {};

	static Texture *load(const char *id, CL_ResourceManager *resources);
	static Texture *load(CL_SurfaceProvider *provider, bool del);

// Operations:
public:
	void put_screen(
		int x,
		int y,
		short hotspotX = -1,
		short hotspotY = -1,
		float rotation = 0.0f,
		RGBA *rgba = NULL,
		int spr_no = 0);

	void put_screen(
		int x,
		int y,
		short hotspotX,
		short hotspotY,
		float scaleX,
		float scaleY,
		float rotation = 0.0f,
		RGBA *rgba = NULL,
		int spr_no = 0);
};

#endif