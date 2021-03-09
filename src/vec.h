#ifndef VEC_H
#define VEC_H

#include "int_types.h"

typedef struct Vec {
	s32 x;
	s32 y;
} Vec;

Vec vec_new(s32 x, s32 y);

#endif // VEC_H
