#include <SDL2/SDL.h>
#include "event.h"
#include "vec.h"
#include "int_types.h"

u8 event_poll_event(Event *e) {
	SDL_Event sdl_event;
	if (!SDL_PollEvent(&sdl_event)) {
		return 0;
	}
	e->type = 0;
	e->data = (EventData) {0};
	switch (sdl_event.type) {
	case SDL_QUIT:
		e->type = EVENT_QUIT;
		break;
	case SDL_MOUSEMOTION:
		e->type = EVENT_MOUSE_MOVE;
		e->data.pos.x = sdl_event.motion.x;
		e->data.pos.y = sdl_event.motion.y;
		break;
	default:
		e->type = EVENT_UNHANDLED;
	}
}
