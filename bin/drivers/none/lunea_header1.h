#pragma once

#include <math.h>

#define sinf(x) ((float)sin((double)(x)))
#define cosf(x) ((float)cos((double)(x)))

struct mouse_struct {
	int x;
	int y;
	bool left;
	bool middle;
	bool right;
	bool xb1;
	bool xb2;
	int wheel;
	bool visible;
	bool clicked;

	void show() {  }
	void hide() {  }
} *mouse;