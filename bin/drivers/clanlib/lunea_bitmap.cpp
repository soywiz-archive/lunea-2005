#include <lunea_bitmap.h>

#include <lunea_header1.h>

//#include <ClanLib\Display\graphic_context.h>

#include <iostream>

// COLOR
unsigned int color_make(int r, int g, int b) {
	return (unsigned int)((r & 0xff) | ((g & 0xff) << 8) | ((b & 0xff) << 16)) | 0xff000000;
}

unsigned int color_make_alpha(int r, int g, int b, int alpha) {
	return (unsigned int)((r & 0xff) | ((g & 0xff) << 8) | ((b & 0xff) << 16) | ((alpha & 0xff) << 24));
}

// DRAW
void draw_bitmap(Bitmap *src, Bitmap *dst, int x, int y, int cx, int cy, float alpha, float size, float angle) {
	if (src == NULL) return;
	src->setSize(size);
	src->setAngle(angle);
	src->setAlpha(alpha);
	src->setCenter(cx, cy);
	//src->surface.set_blend_func(blend_zero, blend_dst_alpha);
	src->surface.set_blend_func(blend_src_alpha, blend_one_minus_src_alpha);
	//src->surface.set_blend_func(blend_src_alpha, blend_one_minus_dest_alpha);

	if (dst != NULL) {
		src->drawOn(dst, x, y);
	} else {
		src->draw(x, y);
	}
}

#define cl_color_from_rgb(rgb) CL_Color(((rgb) & 0xff), (((rgb) >> 8) & 0xff), (((rgb) >> 16) & 0xff), (((rgb) >> 24) & 0xff))
#define draw_2point_common(method)\
	if (dst != NULL) {\
		dst->makeCanvas();\
		dst->canvas->get_gc()->method(x1, y1, x2, y2, cl_color_from_rgb(rgb));\
	} else {\
		CL_Display::method(x1, y1, x2, y2, cl_color_from_rgb(rgb));\
	}

#define draw_rect_common(method)\
	if (dst != NULL) {\
		dst->makeCanvas();\
		dst->canvas->get_gc()->method(CL_Rect(x1, y1, x2, y2), cl_color_from_rgb(rgb));\
	} else {\
		CL_Display::method(CL_Rect(x1, y1, x2, y2), cl_color_from_rgb(rgb));\
	}

#define draw_quad_common(method)\
	if (dst != NULL) {\
		dst->makeCanvas();\
		dst->canvas->get_gc()->method(CL_Quad(x1, y1, x2, y2, x3, y3, x4, y4), cl_color_from_rgb(rgb));\
	} else {\
		CL_Display::method(CL_Quad(x1, y1, x2, y2, x3, y3, x4, y4), cl_color_from_rgb(rgb));\
	}

void draw_pixel(Bitmap *dst, int x, int y, unsigned int rgb) {
	if (dst != NULL) {
		dst->makeCanvas();
		dst->canvas->get_gc()->draw_pixel(x, y, cl_color_from_rgb(rgb));
	} else {
		CL_Display::draw_pixel(x, y, cl_color_from_rgb(rgb));
	}
}

void draw_line(Bitmap *dst, int x1, int y1, int x2, int y2, unsigned int rgb) {
	draw_2point_common(draw_line);
}

void draw_rect(Bitmap *dst, int x1, int y1, int x2, int y2, unsigned int rgb) {
	draw_rect_common(draw_rect);
}

void draw_rect_fill(Bitmap *dst, int x1, int y1, int x2, int y2, unsigned int rgb) {
	draw_rect_common(fill_rect);
}

void draw_quad(Bitmap *dst, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, unsigned int rgb) {
	draw_quad_common(draw_quad);
}

void draw_quad_fill(Bitmap *dst, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, unsigned int rgb) {
	draw_quad_common(fill_quad);
}

// BITMAP

Bitmap *bitmap_load(const char *name) {
	CL_Surface test = CL_Surface(name);

	Bitmap *ret  = new Bitmap();
	ret->surface = test;

	return ret;
}

Bitmap *bitmap_load_from_resource(const char *name) {
	char tname[L_tmpnam];
	Bitmap *retval;

	if (create_file_from_resource(name, tname) != 0) {
		return (Bitmap *)0;
	}

	retval = bitmap_load(tname);
	delete_file_created_from_resource(tname);

	return retval;
}

Bitmap *bitmap_create(int width, int height) {
	return (Bitmap *)0;
}

int bitmap_width(Bitmap *bmp) {
	if (!bmp) return 0;

	return bmp->surface.get_width();
}

int bitmap_height(Bitmap *bmp) {
	if (!bmp) return 0;

	return bmp->surface.get_height();
}



Bitmap *screen = 0;



/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

#define Bitmap_Canvas_Start\
	bool mustDelete = false;\
	if (bmp->canvas == 0) {\
		bmp->makeCanvas();\
		mustDelete = true;\
	}

#define Bitmap_Canvas_End\
	if (mustDelete) bmp->deleteCanvas();

Bitmap::Bitmap() {
	canvas = 0;
}

Bitmap::~Bitmap() {
	if (canvas != 0) delete canvas;
}

Bitmap* Bitmap::loadFromFile(const char *fileName) {
	Bitmap* retval = new Bitmap();
	retval->surface = CL_Surface(fileName);
	return retval;
}

Bitmap* Bitmap::createBitmap(int width, int height) {
	Bitmap* retval = new Bitmap();
	retval->surface = CL_Surface("");
	//retval->surface = *new CL_Surface(new CL_NEWProvider_Generic(width, height));
	return retval;
}

void Bitmap::setSize(float size) {
	surface.set_scale(size, size);
}

void Bitmap::setAngle(float angle) {
	surface.set_angle(angle);
}

void Bitmap::setAlpha(float alpha) {
	surface.set_alpha(alpha);
}

void Bitmap::setCenter(int x, int y) {
	CL_Origin _origin; int _x, _y;
	/*
	surface.get_alignment(_origin, _x, _y);
	surface.set_alignment(_origin, x, y);
	//surface.set_alignment(origin_top_left, -x, -y);
	*/
	surface.get_alignment(_origin, _x, _y);
	surface.set_alignment(_origin, -x, y);

	//std::cout << "x: " << x << " - y: " << y << "\n";

	surface.get_rotation_hotspot(_origin, _x, _y);
	//surface.set_rotation_hotspot(origin_top_left, x, y);
	//surface.set_rotation_hotspot(_origin, x, y);
	surface.set_rotation_hotspot(_origin, 0, 0);
}

void Bitmap::draw(int x, int y) {
	//surface.set_blend_func(blend_src_alpha, blend_one_minus_src_alpha);
	//sff->set_blend_func(blend_src_alpha, blend_one_minus_src_alpha);

	surface.draw(x, y);
}

void Bitmap::drawOn(Bitmap* bmp, int x, int y) {
	Bitmap_Canvas_Start;

	surface.draw(x, y, bmp->canvas->get_gc());

	Bitmap_Canvas_End;
}

void Bitmap::drawSubstract(Bitmap* bmp, int x, int y) {
	Bitmap_Canvas_Start;

	surface.set_blend_func(blend_zero, blend_one_minus_src_alpha);

	surface.draw(x, y, bmp->canvas->get_gc());

	surface.set_blend_func(blend_src_alpha, blend_one_minus_src_alpha);

	Bitmap_Canvas_End;
}

void Bitmap::makeCanvas() {
	if (canvas == 0) delete canvas;
	canvas = new CL_Canvas(surface);
}

void Bitmap::deleteCanvas() {
	delete canvas;
	canvas = 0;
}