#include "lunea_bitmap.h"

#include <iostream>

void bitmap_draw(Bitmap *src, Bitmap *dst, int x, int y, int cx, int cy, float alpha, float size, float angle) {
	//std::cout << "bitmap_draw()\n";
}

Bitmap *bitmap_load(const char *name) {
	return (Bitmap *)0;
}

Bitmap *bitmap_load_from_resource(const char *name) {
	return (Bitmap *)0;
}

Bitmap *bitmap_create(int width, int height) {
	return (Bitmap *)0;
}

int bitmap_width(Bitmap *bmp) {
	return 0;
}

int bitmap_height(Bitmap *bmp) {
	return 0;
}

Bitmap *screen = 0;