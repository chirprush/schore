#include <SDL2/SDL.h>
#include <stdlib.h>
#include "window.h"
#include "result.h"
#include "int_types.h"
#include "color.h"

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

void window_set_draw_color(Window *window, const Color *color) {
	SDL_SetRenderDrawColor(window->renderer, color->r, color->g, color->b, color->a);
}

void window_clear(Window *window, const Color *color) {
	window_set_draw_color(window, color);
	SDL_RenderClear(window->renderer);
}

void window_present(Window *window) {
	SDL_RenderPresent(window->renderer);
}

void window_delay(f32 seconds) {
	SDL_Delay(seconds * 1000.0f);
}

void window_free(Window *window) {
	SDL_DestroyRenderer(window->renderer);
	SDL_DestroyWindow(window->window);
}

void window_quit() {
	SDL_Quit();
}
