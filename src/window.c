#include <SDL2/SDL.h>
#include <stdlib.h>
#include "window.h"
#include "result.h"
#include "int_types.h"

WindowResult window_new(const char *title, u32 w, u32 h) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *sdl_window = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			w, h,
			SDL_WINDOW_RESIZABLE);
	if (sdl_window == NULL) {
		return (WindowResult)result_err(EXIT_FAILURE);
	}
	SDL_Renderer *sdl_renderer = SDL_CreateRenderer(
			sdl_window,
			-1,
			SDL_RENDERER_ACCELERATED);
	if (sdl_renderer == NULL) {
		SDL_DestroyWindow(sdl_window);
		return (WindowResult)result_err(EXIT_FAILURE);
	}
	Window window = {
		sdl_window,
		sdl_renderer,
		1,
		w,
		h
	};
	return (WindowResult)result_ok(window);
}
