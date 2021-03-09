#include "int_types.h"
#include "vec.h"

Vec vec_new(s32 x, s32 y) {
	Vec value = {
		x,
		y
	};
	return value;
}
