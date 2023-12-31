#pragma once

#include <lunea_bitmap.h>
#include <lunea_lprocess_base.h>

class LPROCESS : public LPROCESS_BASE {
protected:
	void __init();
public:
	void __process();
	Bitmap   *bitmap;
	float angle;
	int size;
	int alpha;
	int cx;
	int cy;
};

extern LPROCESS      *CURRENT_PROCESS;