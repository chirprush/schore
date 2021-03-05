#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include "int_types.h"
#include "result.h"
#include "color.h"

typedef struct Window {
	SDL_Window *window;
	SDL_Renderer *renderer;
	u8 running;
	u32 w;
	u32 h;
} Window;

typedef result_type(Window, u8) WindowResult;

WindowResult window_new(const char *title, u32 w, u32 h);

void window_set_draw_color(Window *window, const Color *color);

void window_clear(Window *window, const Color *color);

void window_present(Window *window);

void window_delay(f32 seconds);

void window_free(Window *window);

void window_quit();

#endif // WINDOW_H
