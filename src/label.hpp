#ifndef LABEL_HPP
#define LABEL_HPP

#include <SDL2/SDL_ttf.h>
#include <string>
#include "window.hpp"
#include "color.hpp"
#include "widget.hpp"

constexpr int NORMAL = TTF_STYLE_NORMAL;
constexpr int BOLD = TTF_STYLE_BOLD;
constexpr int ITALIC = TTF_STYLE_ITALIC;

struct Label : Widget {
	std::string text;
	int ftsize;
	int style;
	Color color;

	Label(std::string text, int ftsize, int style, const Color &color);

	void render(Window &win, const Rect &bounds) const;
	void update(Window &win);
	void free();
};


#endif // LABEL_HPP
