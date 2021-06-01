#include "rect.hpp"

bool Rect::contains(Vec2 &v) const {
	return v.x >= pos.x && v.y >= pos.y && v.x <= (pos.x + w) && v.y <= (pos.y + h);
}
