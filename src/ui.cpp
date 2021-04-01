#include "ui.hpp"
#include "color.hpp"
#include "window.hpp"
#include "rect.hpp"

Ui::Ui(Widget *child) : child(child) {}

Ui::~Ui() {
	child->free();
	delete child;
}

void Ui::render(Window &win, const Rect &bounds) const {
	child->render(win, bounds);
}

void Ui::update(Window &win) {
	child->update(win);
}

void Ui::free() {}

Length::Length(int absolute) : absolute(absolute) {
	type = LengthType::Absolute;
}

Length::Length(float percent) : percent(percent) {
	type = LengthType::Percent;
}

bool Length::is_abs() const {
	return type == LengthType::Absolute;
}

bool Length::is_per() const {
	return type == LengthType::Percent;
}

VertSplit::VertSplit(Widget *left, Widget *right, const Length &length) : left(left), right(right), length(length) {}

void VertSplit::render(Window &win, const Rect &bounds) const {
	int sep;
	if (length.is_abs()) {
		sep = length.absolute;
	} else {
		sep = (int)(length.percent * bounds.h);
	}
	const Rect &left_bounds = Rect(Vec2(bounds.pos.x, bounds.pos.y), bounds.w, sep);
	const Rect &right_bounds = Rect(Vec2(bounds.pos.x, bounds.pos.y + sep), bounds.w, bounds.h - sep);
	left->render(win, left_bounds);
	right->render(win, right_bounds);
}

void VertSplit::update(Window &win) {
	left->update(win);
	right->update(win);
}

void VertSplit::free() {
	left->free();
	delete left;
	right->free();
	delete right;
}

HorSplit::HorSplit(Widget *left, Widget *right, const Length &length) : left(left), right(right), length(length) {}

void HorSplit::render(Window &win, const Rect &bounds) const {
	int sep;
	if (length.is_abs()) {
		sep = length.absolute;
	} else {
		sep = (int)(length.percent * bounds.w);
	}
	const Rect &left_bounds = Rect(Vec2(bounds.pos.x, bounds.pos.y), sep, bounds.h);
	const Rect &right_bounds = Rect(Vec2(bounds.pos.x + sep, bounds.pos.y), bounds.w - sep, bounds.h);
	left->render(win, left_bounds);
	right->render(win, right_bounds);
}

void HorSplit::update(Window &win) {
	left->update(win);
	right->update(win);
}

void HorSplit::free() {
	left->free();
	delete left;
	right->free();
	delete right;
}

ColoredRect::ColoredRect(Color color) : color(color) {}

void ColoredRect::render(Window &win, const Rect &bounds) const {
	win.renderRect(bounds, color);
}

void ColoredRect::update(Window &win) {}

void ColoredRect::free() {}
