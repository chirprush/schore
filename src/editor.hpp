#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <vector>
#include <string>
#include "rect.hpp"
#include "window.hpp"
#include "color.hpp"
#include "widget.hpp"

constexpr int ITEM_YPADDING = 2;
constexpr int ITEM_XPADDING = 10;

constexpr int ITEM_INDENT = 30;

constexpr Color TOPIC_FG = 0x61afef;
constexpr Color TEXT_FG = 0xebdbef;

constexpr int TOPIC_BULLET_RADIUS = 7;
constexpr int TOPIC_SPACE = 2 * TOPIC_BULLET_RADIUS + 10;
constexpr int TOPIC_BULLET_THICKNESS = 2;

constexpr int TOPIC_SZ = 25;
constexpr int TEXT_SZ = 20;

enum class ItemType { Topic, Text };

struct Item : Widget {
	ItemType type;
	std::string content;
	std::vector<Item> children;
	bool focused;

	Item(ItemType type, std::string content);

	int height(Window &win) const;

	void render(Window &win, const Rect &bounds) const;
	void update(Window &win, const Rect &bounds);
	void free();
};

constexpr Color EDITOR_BG = 0x1d2021;

struct Editor : Widget {
	std::vector<Item> children;

	Editor();

	void render(Window &win, const Rect &bounds) const;
	void update(Window &win, const Rect &bounds);
	void free();
};


#endif // EDITOR_HPP
