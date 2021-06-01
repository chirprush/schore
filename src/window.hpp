#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <map>
#include "color.hpp"
#include "rect.hpp"

constexpr int TEXT_NORMAL = TTF_STYLE_NORMAL;
constexpr int TEXT_BOLD = TTF_STYLE_BOLD;
constexpr int TEXT_ITALIC = TTF_STYLE_ITALIC;

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
	Vec2 mouse_pos = {0, 0};

	Window(const char *title, int w, int h, const char *font_path);
	~Window();

	void renderLine(const Vec2 &pos1, const Vec2 &pos2, const Color &color);
	void renderRect(const Rect &rect, const Color &color);
	void renderText(const Vec2 &pos, const char *text, const int ftsize, const Color &color, const int style);
	void renderCircle(const Vec2 &pos, int radius, const Color &color);

	TTF_Font *ensureFont(int ftsize);
	int getFontHeight(int ftsize);
	int getTextWidth(const char* text, int ftsize);

	void clear(const Color &color);
	void present();

	void delay(float s);
};

#endif // WINDOW_HPP
