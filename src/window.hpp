#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <map>
#include "color.hpp"
#include "rect.hpp"

struct Window {
	SDL_Window *window;
	SDL_Renderer *renderer;
	const char *font_path;
	/*
	 * SDL requires that you pass in the font name AND the font size
	 * to create a TTF_Font *. Because we would ideally want multiple
	 * text sizes, we create a font cache using a map.
	*/
	std::map<int, TTF_Font *> fonts;
	bool running;
	int w;
	int h;

	Window(const char *title, int w, int h, const char *font_path);
	~Window();

	void renderLine(const Vec2 &pos1, const Vec2 &pos2, const Color &color);
	void renderRect(const Rect &rect, const Color &color);

	void clear(const Color &color);
	void present();

	void delay(float s);
};

#endif // WINDOW_HPP
