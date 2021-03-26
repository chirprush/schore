#ifndef RECT_HPP
#define RECT_HPP

struct Vec2 {
	int x;
	int y;

	constexpr Vec2(int x, int y) : x(x), y(y) {}
};


struct Rect {
	Vec2 pos;
	int w;
	int h;

	constexpr Rect(Vec2 pos, int w, int h) : pos(pos), w(w), h(h) {}
};


#endif // RECT_HPP
