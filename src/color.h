#ifndef COLOR_H
#define COLOR_H

#include "int_types.h"

typedef struct Color {
	u8 r;
	u8 g;
	u8 b;
	u8 a;
} Color;

Color color_new(u8 r, u8 g, u8 b, u8 a);

#endif // COLOR_H
