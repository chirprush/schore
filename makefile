CXX = g++
CFLAGS = -g -Wall -Werror
LDFLAGS =

CFLAGS += `pkg-config --cflags sdl2`
LDFLAGS += `pkg-config --libs sdl2`

LDFLAGS += `pkg-config --libs SDL2_ttf`
LDFLAGS += `pkg-config --libs SDL2_gfx`

OUTPUT = ./bin/main

cfiles = $(wildcard src/*.cpp)
objects = $(cfiles:src/%.cpp=bin/%.o)

main: $(objects)
	$(CXX) -o $(OUTPUT) $(objects) $(CFLAGS) $(LDFLAGS)

$(objects):
	$(CXX) -c $(@:bin/%.o=src/%.cpp) -o $@ $(CFLAGS) $(LDFLAGS)

run: main
	$(OUTPUT)

clean:
	rm bin/*

.PHONY: main run clean
