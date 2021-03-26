#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "window.hpp"
#include "rect.hpp"

struct Widget {
	virtual ~Widget() {}
	virtual void render(Window &win, const Rect &bounds) const = 0;
	virtual void update(Window &win) = 0;
	virtual void free() = 0;
};


#endif // WIDGET_HPP
