#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
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

void Window::renderLine(const Vec2 &pos1, const Vec2 &pos2, const Color &color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(renderer, pos1.x, pos1.y, pos2.x, pos2.y);
}

void Window::renderRect(const Rect &bounds, const Color &color) {
	SDL_Rect rect;
	rect.x = bounds.pos.x;
	rect.y = bounds.pos.y;
	rect.w = bounds.w;
	rect.h = bounds.h;
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
}

void Window::renderText(const Vec2 &pos, const char *text, const int ftsize, const Color &color, const int style) {
	TTF_Font *font = ensureFont(ftsize);
	SDL_Color fg = {color.r, color.g, color.b, color.a};
	TTF_SetFontStyle(font, style);
	SDL_Surface *surface = TTF_RenderText_Blended(font, text, fg);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect dst;
	dst.x = pos.x;
	dst.y = pos.y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, texture, NULL, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Window::renderCircle(const Vec2 &pos, int radius, const Color &color) {
	filledEllipseRGBA(renderer, pos.x, pos.y, radius, radius, color.r, color.g, color.b, color.a);
}

TTF_Font *Window::ensureFont(int ftsize) {
	auto it = fonts.find(ftsize);
	if (it == fonts.end()) {
		TTF_Font *font = TTF_OpenFont(font_path, ftsize);
		fonts.insert(std::pair<int, TTF_Font *>(ftsize, font));
		return font;
	}
	return it->second;
}

int Window::getFontHeight(int ftsize) {
	TTF_Font *font = ensureFont(ftsize);
	return TTF_FontHeight(font);
}

int Window::getTextWidth(const char *text, int ftsize) {
	TTF_Font *font = ensureFont(ftsize);
	int h = 0;
	TTF_SizeText(font, text, NULL, &h);
	return h;
}

void Window::clear(const Color &color) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);
}

void Window::present() {
	SDL_RenderPresent(renderer);
}

void Window::delay(float s) {
	SDL_Delay((int)(1000 * s));
}
