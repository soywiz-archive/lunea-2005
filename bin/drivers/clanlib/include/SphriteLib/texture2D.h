#ifndef _SPHRITELIB_TEXTURE2D_H_
#define _SPHRITELIB_TEXTURE2D_H_

#include <ClanLib/display.h>

class Texture : public CL_Surface
{
// Construction:
public:
	Texture() {};

	static Texture *load(const char *id, CL_ResourceManager *resources);
	static Texture *load(CL_SurfaceProvider *provider, bool del);
};

#endif