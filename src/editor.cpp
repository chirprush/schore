#include <vector>
#include <string>
#include "rect.hpp"
#include "color.hpp"
#include "editor.hpp"
#include "window.hpp"

Item::Item(ItemType type, std::string content) : type(type), content(content), focused(false) {}

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
	int h;
	if (type == ItemType::Topic) {
		h = win.getFontHeight(TOPIC_SZ);
		// Render bullet topic circle
		win.renderCircle(Vec2(bounds.pos.x + TOPIC_BULLET_RADIUS + ITEM_XPADDING, bounds.pos.y + h / 2), TOPIC_BULLET_RADIUS, TOPIC_FG);
		win.renderCircle(Vec2(bounds.pos.x + TOPIC_BULLET_RADIUS + ITEM_XPADDING, bounds.pos.y + h / 2), TOPIC_BULLET_RADIUS - TOPIC_BULLET_THICKNESS, EDITOR_BG);
		// Render bullet topic text
		win.renderText(Vec2(bounds.pos.x + TOPIC_SPACE + ITEM_XPADDING, bounds.pos.y), content.c_str(), TOPIC_SZ, TOPIC_FG, TEXT_BOLD);
	} else {
		h = win.getFontHeight(TEXT_SZ);
		win.renderText(Vec2(bounds.pos.x + ITEM_XPADDING, bounds.pos.y), content.c_str(), TEXT_SZ, TEXT_FG, TEXT_NORMAL);
	}
	h += ITEM_YPADDING;
	for (const auto &i : children) {
		i.render(win, Rect(Vec2(bounds.pos.x + ITEM_INDENT, bounds.pos.y + h), bounds.w, bounds.h));
		h += i.height(win);
		h += ITEM_YPADDING;
	}
}

void Item::update(Window &win, const Rect &bounds) {
}

void Item::free() {}

Editor::Editor() : children() {}

void Editor::render(Window &win, const Rect &bounds) const {
	win.renderRect(bounds, EDITOR_BG);
	int h = 0;
	for (const auto &i : children) {
		i.render(win, Rect(Vec2(bounds.pos.x, bounds.pos.y + h), bounds.w, bounds.h));
		h += i.height(win);
	}
}

void Editor::update(Window &win, const Rect &bounds) {
	for (auto &i : children) {
		i.update(win, bounds);
	}
}

void Editor::free() {}
