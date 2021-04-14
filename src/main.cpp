#include <SDL2/SDL.h>
#include "editor.hpp"
#include "color.hpp"
#include "ui.hpp"
#include "rect.hpp"
#include "event.hpp"
#include "window.hpp"

constexpr Color BACKGROUND_COLOR = 0x1d2021;
constexpr Color BAR_COLOR = 0x2d3031;
constexpr Color SIDE_PANE_COLOR = 0x242728;
constexpr float delay = 1.0f / 30;

int main(int argc, char *argv[]) {
	Window win = Window("Schore", 1920, 1080, "./fonts/Inconsolata.otf");
	const Rect bounds = Rect(Vec2(0, 0), win.w, win.h);
	auto ed = new Editor();
	auto text = Item(ItemType::Text);
	text.content = "Finish Road to War poster (Thursday)";
	auto topic = Item(ItemType::Topic);
	topic.content = "Social Studies";
	topic.children.push_back(text);
	auto parent_topic = Item(ItemType::Topic);
	parent_topic.content = "Homework";
	parent_topic.children.push_back(topic);
	ed->items.push_back(parent_topic);
	Ui ui = Ui(
		new HorSplit(
			new ColoredRect(BAR_COLOR),
			new VertSplit(
				new ColoredRect(SIDE_PANE_COLOR),
				ed,
				0.20f
			),
			0.05f
		)
	);
	Event e = {};
	while (win.running) {
		while (Event::get_event(&e)) {
			switch (e.type) {
			case EventType::Quit:
				win.running = false;
				break;
			default:
				break;
			}
		}
		win.clear(BACKGROUND_COLOR);
		ui.render(win, bounds);
		win.present();
		win.delay(delay);
	}
	return 0;
}
