#include <stdio.h>
#include "vec.h"

int main(int argc, char *argv[]) {
	Vec v = vec_new(2, 2);
	printf("%d %d", v.x, v.y);
	return 0;
}
