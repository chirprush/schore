#ifndef LABEL_HPP
#define LABEL_HPP

#include "window.hpp"
#include "color.hpp"
#include "widget.hpp"

struct Label : Widget {
	const char *text;
	int ftsize;
	Color color;

	Label(const char *text, int ftsize, const Color &color);

	void render(Window &win, const Rect &bounds) const;
	void update(Window &win);
	void free();
};


#endif // LABEL_HPP
