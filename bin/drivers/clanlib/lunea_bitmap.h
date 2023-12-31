#pragma once

#include <ClanLib\Core\IOData\inputsource.h>
#include <ClanLib\Core\IOData\inputsource_memory.h>
#include <ClanLib\Display\canvas.h>
#include <ClanLib\Display\surface.h>
#include <ClanLib\Display\Providers\jpeg_provider.h>

#include <lunea_debug.h>
#include <lunea_define.h>

class Bitmap {
public:
	CL_Surface  surface;
	CL_Canvas  *canvas;

	Bitmap();
	~Bitmap();
	static Bitmap* loadFromFile(const char *fileName);
	static Bitmap* createBitmap(int width, int height);
	void setSize(float size);
	void setAngle(float angle);
	void setAlpha(float alpha);
	void setCenter(int x, int y);
	void draw(int x, int y);
	void drawOn(Bitmap* bmp, int x, int y);
	void drawSubstract(Bitmap* bmp, int x, int y);
	void makeCanvas();
	void deleteCanvas();
};

// COLOR
unsigned int color_make(int r, int g, int b);
unsigned int color_make_alpha(int r, int g, int b, int alpha);

// DRAW
void draw_bitmap(Bitmap *src, Bitmap *dst, int x, int y, int cx, int cy, float alpha, float size, float angle);
void draw_pixel(Bitmap *dst, int x, int y, unsigned int rgb);
void draw_line(Bitmap *dst, int x1, int y1, int x2, int y2, unsigned int rgb);
void draw_rect(Bitmap *dst, int x1, int y1, int x2, int y2, unsigned int rgb);
void draw_rect_fill(Bitmap *dst, int x1, int y1, int x2, int y2, unsigned int rgb);
void draw_quad(Bitmap *dst, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, unsigned int rgb);
void draw_quad_fill(Bitmap *dst, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, unsigned int rgb);

// BITMAP
Bitmap *bitmap_load(const char *name);
extern Bitmap *bitmap_load_from_resource(const char *name);
Bitmap *bitmap_create(int width, int height);
int bitmap_width(Bitmap *bmp);
int bitmap_height(Bitmap *bmp);

extern Bitmap *screen;