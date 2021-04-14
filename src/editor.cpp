#include <vector>
#include "rect.hpp"
#include "label.hpp"
#include "color.hpp"
#include "editor.hpp"
#include "window.hpp"

Item::Item(ItemType type) : type(type), content(""), focused(false) {}

Label Item::getLabel() const {
	switch (type) {
	case ItemType::Topic:
		return Label(content, TOPIC_SZ, BOLD, TOPIC_FG);
	default:
		return Label(content, TEXT_SZ, NORMAL, TEXT_FG);
	}
}

int Item::height(Window &win) const {
	int h = win.getFontHeight(type == ItemType::Topic ? TOPIC_SZ : TEXT_SZ);
	h += ITEM_YPADDING;
	for (const auto &i : children) {
		h += i.height(win);
		h += ITEM_YPADDING;
	}
	return h;
}

void Item::render(Window &win, const Rect &bounds) const {
	Label label = getLabel();
	int h = win.getFontHeight(label.ftsize);
	if (type == ItemType::Topic) {
		win.renderCircle(Vec2(bounds.pos.x + TOPIC_BULLET_RADIUS + ITEM_XPADDING, bounds.pos.y + h / 2), TOPIC_BULLET_RADIUS, TOPIC_FG);
		win.renderCircle(Vec2(bounds.pos.x + TOPIC_BULLET_RADIUS + ITEM_XPADDING, bounds.pos.y + h / 2), TOPIC_BULLET_RADIUS - TOPIC_BULLET_THICKNESS, EDITOR_BG);
		label.render(win, Rect(Vec2(bounds.pos.x + TOPIC_SPACE + ITEM_XPADDING, bounds.pos.y), bounds.w, h));
	} else {
		label.render(win, Rect(Vec2(bounds.pos.x + ITEM_XPADDING, bounds.pos.y), bounds.w, h));
	}
	h += ITEM_YPADDING;
	for (const auto &i : children) {
		i.render(win, Rect(Vec2(bounds.pos.x + ITEM_INDENT, bounds.pos.y + h), bounds.w, bounds.h));
		h += i.height(win);
		h += ITEM_YPADDING;
	}
}

void Item::update(Window &win) {}

void Item::free() {}

Editor::Editor() : items() {}

void Editor::render(Window &win, const Rect &bounds) const {
	win.renderRect(bounds, EDITOR_BG);
	int h = 0;
	for (const auto &i : items) {
		i.render(win, Rect(Vec2(bounds.pos.x, bounds.pos.y + h), bounds.w, bounds.h));
		h += i.height(win);
	}
}

void Editor::update(Window &win) {
	for (auto &i : items) {
		i.update(win);
	}
}

void Editor::free() {}
