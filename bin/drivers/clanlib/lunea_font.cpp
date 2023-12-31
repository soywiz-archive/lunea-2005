#include <lunea_font.h>

#include <string>



Font::Font() {
}

Font::~Font() {
}

Font *Font::create(const std::string &font_name, int height) {
	Font *retval = new Font();
	retval->font = CL_Font(font_name, height);
	return retval;
}

//#define cl_color_from_rgb_f(rgb) CL_Color(((float)((rgb) & 0xff) / 255), ((float)(((rgb) >> 8) & 0xff) / 255), ((float)(((rgb) >> 16) & 0xff) / 255), ((float)(((rgb) >> 24) & 0xff) / 255))

#define cl_color_from_rgb(rgb) CL_Color(((rgb) & 0xff), (((rgb) >> 8) & 0xff), (((rgb) >> 16) & 0xff), (((rgb) >> 24) & 0xff))

extern CL_GraphicContext *cl_window_gc;

Font *font_create(const std::string &font_name, int height) {
	return Font::create(font_name, height);
}

void draw_font(Font *src, Bitmap *dst, const std::string &str, int x, int y, unsigned int rgba, int align) {
	if (!src) return;

	CL_GraphicContext *gc;

	//src->font.set_color(cl_color_from_rgb_f(rgba));
	src->font.set_color(cl_color_from_rgb(rgba));
	if (dst == NULL) {
		gc = cl_window_gc;
	} else {
		dst->makeCanvas();
		gc = dst->canvas->get_gc();
	}

	int ax, ay;

	if (align & FONT_H_RIGHT) {
		ax = (src->font.get_width(str));
	} else if (align & FONT_H_CENTER) {
		ax = (src->font.get_width(str) / 2);
	} else {
		ax = 0;
	}

	if (align & FONT_V_BOTTOM) {
		ay = (src->font.get_height(str));
	} else if (align & FONT_V_CENTER) {
		ay = (src->font.get_height(str) / 2);
	} else {
		ay = 0;
	}

	src->font.set_blend_func(blend_src_alpha, blend_one_minus_src_alpha);

	src->font.draw(x - ax, y - ay, str, gc);
}