#include "int_types.h"
#include "color.h"

Color color_new(u8 r, u8 g, u8 b, u8 a) {
	Color color = {
		r,
		g,
		b,
		a
	};
	return color;
}
