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
constexpr float delay = 1.0f / 60;

int main(int argc, char *argv[]) {
	Window win = Window("Schore", 1920, 1080, "./fonts/Inconsolata.otf");
	Rect bounds = Rect(Vec2(0, 0), win.w, win.h);
	Item it = Item(ItemType::Topic, "Topic");
	Item sub = Item(ItemType::Text, "Topic text");
	it.children.push_back(sub);
	Editor *ed = new Editor();
	ed->children.push_back(it);
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
			case EventType::Resize:
				bounds.w = e.resize.w;
				bounds.h = e.resize.h;
				break;
			case EventType::MouseMove:
				win.mouseX = e.mouse_move.x;
				win.mouseY = e.mouse_move.y;
				break;
			default:
				break;
			}
		}
		win.clear(BACKGROUND_COLOR);
		ui.render(win, bounds);
		ui.update(win, bounds);
		win.present();
		win.delay(delay);
	}
	return 0;
}
