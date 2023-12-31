#include "lunea_lprocess.h"

void LPROCESS::__init() {
	bitmap = 0;
	angle = 0;
	size = 100;
	alpha = 255;
	LPROCESS_BASE::__init();
}

void LPROCESS::__process() {
	while (angle >= 360) angle -= 360;

	LPROCESS_BASE::__process();
}