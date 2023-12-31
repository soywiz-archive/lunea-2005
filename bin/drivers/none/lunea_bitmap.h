#pragma once

typedef int Bitmap;

void bitmap_draw(Bitmap *src, Bitmap *dst, int x, int y, int cx, int cy, float alpha, float size, float angle);
Bitmap *bitmap_load(const char *name);
Bitmap *bitmap_load_from_resource(const char *name);
Bitmap *bitmap_create(int width, int height);
int bitmap_width(Bitmap *bmp);
int bitmap_height(Bitmap *bmp);

extern Bitmap *screen;