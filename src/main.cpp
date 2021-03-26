#include <SDL2/SDL.h>
#include "color.hpp"
#include "ui.hpp"
#include "label.hpp"
#include "rect.hpp"
#include "event.hpp"
#include "window.hpp"

constexpr Color BACKGROUND_COLOR = 0x1d2021;
constexpr Color TEXT_COLOR = 0x61afef;
constexpr float delay = 1.0f / 30;

int main(int argc, char *argv[]) {
	Window win = Window("Schore", 1920, 1080, "./fonts/Hack-Regular-Nerd-Font-Complete.ttf");
	const Rect bounds = Rect(Vec2(0, 0), win.w, win.h);
	auto ui = Ui(new Label("Hello", 20, 0x61afef));
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
