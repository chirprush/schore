#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <map>
#include "label.hpp"
#include "color.hpp"
#include "window.hpp"

Label::Label(const char *text, int ftsize, const Color &color) : text(text), ftsize(ftsize), color(color) {}

void Label::render(Window &win, const Rect &bounds) const {
	TTF_Font *font;
	SDL_Color sdl_color = {color.r, color.g, color.b, color.a};
	auto it = win.fonts.find(ftsize);
	if (it == win.fonts.end()) {
		font = TTF_OpenFont(win.font_path, ftsize);
		win.fonts.insert(std::pair<int, TTF_Font *>(ftsize, font));
	} else {
		font = it->second;
	}
	SDL_Surface *surface = TTF_RenderText_Blended(font, text, sdl_color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(win.renderer, surface);
	SDL_Rect dst;
	dst.x = bounds.pos.x;
	dst.y = bounds.pos.y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(win.renderer, texture, NULL, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void Label::update(Window &win) {}

void Label::free() {}
