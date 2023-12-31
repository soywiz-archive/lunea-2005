#include <ClanLib/application.h>
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>

#include <string>

#include <lunea_bitmap.h>

class Font {
public:
	CL_Font font;

	static Font *create(const std::string &font_name, int height);

	Font();
	~Font();
};

Font *font_create(const std::string &font_name, int height);

void draw_font(Font *src, Bitmap *dst, const std::string &string, int x, int y, unsigned int rgba, int align);

#define FONT_H_LEFT   0x01
#define FONT_H_CENTER 0x02
#define FONT_H_RIGHT  0x04

#define FONT_V_TOP    0x10
#define FONT_V_CENTER 0x20
#define FONT_V_BOTTOM 0x40