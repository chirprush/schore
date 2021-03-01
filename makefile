CC = gcc
CFLAGS = -g
LDFLAGS =

CFLAGS += `pkg-config --cflags sdl2`
LDFLAGS += `pkg-config --libs sdl2`

OUTPUT = ./bin/main

main:
	$(CC) $(CFLAGS) $(LDFLAGS) src/main.c -o $(OUTPUT)

run: main
	$(OUTPUT)

clean:
	rm $(OUTPUT)

.PHONY: run clean
