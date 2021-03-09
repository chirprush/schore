#ifndef EVENT_H
#define EVENT_H

#include <SDL2/SDL.h>
#include "vec.h"
#include "int_types.h"

typedef union EventData {
	char unused; // EVENT_QUIT, EVENT_UNHANDLED
	Vec pos;    // EVENT_MOUSE_MOVE
} EventData;

typedef enum EventType { EVENT_QUIT, EVENT_MOUSE_MOVE, EVENT_UNHANDLED } EventType;

typedef struct Event {
	EventData data;
	EventType type;
} Event;

u8 event_poll_event(Event *e);

#endif // EVENT_H
