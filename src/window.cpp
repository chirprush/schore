#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <map>
#include "window.hpp"

Window::Window(const char *title, int w, int h, const char *font_path) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	this->w = w;
	this->h = h;
	this->running = true;
	SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	this->window = window;
	this->renderer = renderer;
	this->font_path = font_path;
	this->fonts = {};
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	for (auto it = fonts.begin(); it != fonts.end(); ++it) {
		TTF_CloseFont(it->second);
	}
	TTF_Quit();
}

void Window::renderLine(int x1, int y1, int x2, int y2, const Color &color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Window::renderRect(int x, int y, int w, int h, const Color &color) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
}

void Window::renderText(const char *text, int ftsize, int x, int y, const Color &color) {
	TTF_Font *font;
	SDL_Color sdl_color = {color.r, color.g, color.b, color.a};
	auto it = fonts.find(ftsize);
	if (it == fonts.end()) {
		font = TTF_OpenFont(font_path, ftsize);
		fonts.insert(std::pair<int, TTF_Font *>(ftsize, font));
	} else {
		font = it->second;
	}
	SDL_Surface *surface = TTF_RenderText_Blended(font, text, sdl_color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, texture, NULL, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Window::clear(const Color &color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);
}

void Window::present() {
	SDL_RenderPresent(renderer);
}

void Window::delay(int ms) {
	SDL_Delay(ms);
}
