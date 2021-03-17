#include <SDL2/SDL.h>
#include "color.hpp"
#include "event.hpp"
#include "window.hpp"

constexpr Color BACKGROUND_COLOR = 0x1d2021;
constexpr Color TEXT_COLOR = 0x61afef;
constexpr int delay = 1000 / 30;

int main(int argc, char *argv[]) {
	Window window = Window("Schore", 1920, 1080, "./fonts/Hack-Regular-Nerd-Font-Complete.ttf");
	Event e = {};
	while (window.running) {
		while (Event::get_event(&e)) {
			switch (e.type) {
			case EventType::Quit:
				window.running = false;
				break;
			default:
				break;
			}
		}
		window.clear(BACKGROUND_COLOR);
		window.renderText("Hello, World!", 20, 0, 0, TEXT_COLOR);
		window.present();
		window.delay(delay);
	}
	return 0;
}
