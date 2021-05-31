#ifndef UI_HPP
#define UI_HPP

#include "window.hpp"
#include "color.hpp"
#include "widget.hpp"
#include "rect.hpp"

struct Ui : Widget {
	/* Should be dynamically allocated using `new` */
	Widget *child;

	Ui(Widget *child);
	~Ui();

	void render(Window &win, const Rect &bounds) const;
	void update(Window &win, const Rect &bounds);
	void free();
};

enum class LengthType { Absolute, Percent };

struct Length {
	LengthType type;
	int absolute;
	float percent;

	Length(int absolute);
	Length(float percent);

	bool is_abs() const;
	bool is_per() const;
};

struct HorSplit : Widget {
	Widget *left;
	Widget *right;
	Length length;

	HorSplit(Widget *left, Widget *right, const Length &length);

	void render(Window &win, const Rect &bounds) const;
	void update(Window &win, const Rect &bounds);
	void free();
};

struct VertSplit : Widget {
	Widget *left;
	Widget *right;
	Length length;

	VertSplit(Widget *left, Widget *right, const Length &length);

	void render(Window &win, const Rect &bounds) const;
	void update(Window &win, const Rect &bounds);
	void free();
};

// Used to create a solidly colored widget. Useful for testing
struct ColoredRect : Widget {
	Color color;

	ColoredRect(Color color);

	void render(Window &win, const Rect &bounds) const;
	void update(Window &win, const Rect &bounds);
	void free();
};

#endif // UI_HPP
