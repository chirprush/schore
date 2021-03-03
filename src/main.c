#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow(
			"Schore",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			600, 600,
			SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		fprintf(stderr, "Error in creating window: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		fprintf(stderr, "Error in creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		return EXIT_FAILURE;
	}
	SDL_SetRenderDrawColor(renderer, 0x1d, 0x20, 0x21, 0xff);
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
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		SDL_Delay(1.0f / 60);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
