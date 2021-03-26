#ifndef UI_HPP
#define UI_HPP

#include "window.hpp"
#include "widget.hpp"
#include "rect.hpp"

struct Ui : Widget {
	// Should be dynamically allocated memory
	Widget *child;

	Ui(Widget *child);
	~Ui();

	void render(Window &win, const Rect &bounds) const;
	void update(Window &win);
	void free();
};

#endif // UI_HPP
