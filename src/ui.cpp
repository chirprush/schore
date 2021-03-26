#include "ui.hpp"

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
