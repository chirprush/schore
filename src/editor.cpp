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

int Item::getFontSize() const {
	switch (type) {
	case ItemType::Topic:
		return TOPIC_SZ;
		break;
	case ItemType::Text:
		return TEXT_SZ;
		break;
	}
	// Not reachable, but the compiler still complains
	return 0;
}

int Item::getIndent() const {
	switch (type) {
	case ItemType::Topic:
		return TOPIC_SPACE + ITEM_XPADDING;
		break;
	case ItemType::Text:
		return ITEM_XPADDING;
		break;
	}
	return 0;
}


void Item::render(Window &win, const Rect &bounds) const {
	// Assign font size and item attributes
	int ftsize = getFontSize();
	int indent = getIndent();
	int w = win.getTextWidth(content.c_str(), ftsize);
	int h = win.getFontHeight(ftsize);
	// If focused, render item background around text
	if (focused) {
		win.renderRect(Rect(Vec2(bounds.pos.x - ITEM_FOCUSED_PADDING + indent, bounds.pos.y - ITEM_FOCUSED_PADDING), w + ITEM_FOCUSED_PADDING * 2, h + ITEM_FOCUSED_PADDING * 2), ITEM_FOCUSED_BG);
	}
	if (type == ItemType::Topic) {
		// Render bullet topic circle
		win.renderCircle(Vec2(bounds.pos.x + TOPIC_BULLET_RADIUS + ITEM_XPADDING, bounds.pos.y + h / 2), TOPIC_BULLET_RADIUS, TOPIC_FG);
		win.renderCircle(Vec2(bounds.pos.x + TOPIC_BULLET_RADIUS + ITEM_XPADDING, bounds.pos.y + h / 2), TOPIC_BULLET_RADIUS - TOPIC_BULLET_THICKNESS, EDITOR_BG);
		// Render bullet topic text
		win.renderText(Vec2(bounds.pos.x + indent, bounds.pos.y), content.c_str(), ftsize, TOPIC_FG, TEXT_BOLD);
	} else {
		win.renderText(Vec2(bounds.pos.x + indent, bounds.pos.y), content.c_str(), ftsize, TEXT_FG, TEXT_NORMAL);
	}
	// Render children
	h += ITEM_YPADDING;
	for (const auto &i : children) {
		i.render(win, Rect(Vec2(bounds.pos.x + ITEM_INDENT, bounds.pos.y + h), bounds.w, bounds.h));
		h += i.height(win);
		h += ITEM_YPADDING;
	}
}

void Item::update(Window &win, const Rect &bounds) {
	// Assign font size and item attributes
	int ftsize = getFontSize();
	int indent = getIndent();
	int w = win.getTextWidth(content.c_str(), ftsize);
	int h = win.getFontHeight(ftsize);
	// If focused, set field
	const Rect text_bounds = Rect(Vec2(bounds.pos.x + indent, bounds.pos.y), w, h);
	if (text_bounds.contains(win.mouse_pos)) {
		focused = true;
	} else {
		focused = false;
	}
	// Update children
	h += ITEM_YPADDING;
	for (auto &i : children) {
		i.update(win, Rect(Vec2(bounds.pos.x + ITEM_INDENT, bounds.pos.y + h), bounds.w, bounds.h));
		h += i.height(win);
		h += ITEM_YPADDING;
	}
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
	// Update all of the children
	int h = 0;
	for (auto &i : children) {
		i.update(win, Rect(Vec2(bounds.pos.x, bounds.pos.y + h), bounds.w, bounds.h));
		h += i.height(win);
	}
}

void Editor::free() {}
