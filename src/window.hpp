#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <map>
#include "color.hpp"

struct Window {
	SDL_Window *window;
	SDL_Renderer *renderer;
	const char *font_path;
	// SDL requires that you pass in the font name AND the font size
	// to create a TTF_Font *. Because we would ideally want multiple
	// text sizes, we create a font cache using a map.
	std::map<int, TTF_Font *> fonts;
	bool running;
	int w;
	int h;

	Window(const char *title, int w, int h, const char *font_path);
	~Window();

	void renderLine(int x1, int y1, int x2, int y2, const Color &color);
	void renderRect(int x, int y, int w, int h, const Color &color);
	void renderText(const char *text, int ftsize, int x, int y, const Color &color);

	void clear(const Color &color);
	void present();

	void delay(int ms);
};

#endif // WINDOW_HPP
