#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include "int_types.h"
#include "result.h"

typedef struct Window {
	SDL_Window *window;
	SDL_Renderer *renderer;
	u8 running;
	u32 w;
	u32 h;
} Window;

typedef result_type(Window, u8) WindowResult;

WindowResult window_new(const char *title, u32 w, u32 h);

#endif // WINDOW_H
