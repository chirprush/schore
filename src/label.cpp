#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <map>
#include "label.hpp"
#include "color.hpp"
#include "window.hpp"

Label::Label(const std::string &text, int ftsize, int style, const Color &color) : text(text), ftsize(ftsize), style(style), color(color) {}

void Label::render(Window &win, const Rect &bounds) const {
	TTF_Font *font = win.ensureFont(ftsize);
	SDL_Color fg = {color.r, color.g, color.b, color.a};
	TTF_SetFontStyle(font, style);
	SDL_Surface *surface = TTF_RenderText_Blended(font, text.c_str(), fg);
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
