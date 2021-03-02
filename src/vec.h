#ifndef VEC_H
#define VEC_H

#include "int_types.h"

typedef struct Vec {
	s16 x;
	s16 y;
} Vec;

Vec vec_new(s16 x, s16 y);

#endif // VEC_H
