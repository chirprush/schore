#include "int_types.h"
#include "vec.h"

Vec vec_new(s16 x, s16 y) {
	Vec value = {
		x,
		y
	};
	return value;
}
