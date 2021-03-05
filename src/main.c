#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "window.h"
#include "result.h"
#include "color.h"

int main(int argc, char *argv[]) {
	WindowResult win_result = window_new("Schore", 600, 600);
	if (is_err(win_result)) {
		return win_result.value.err_value;
	}
	Window window = win_result.value.ok_value;
	const Color bg = color_new(0x1d, 0x20, 0x21, 0xff);
	int running = 1;
	SDL_Event e;
	while (running) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				running = 0;
				break;
			}
		}
		window_clear(&window, &bg);
		window_present(&window);
		window_delay(1.0f / 60);
	}
	window_free(&window);
	window_quit();
	return 0;
}
