CC = gcc
CFLAGS = -g
LDFLAGS =

CFLAGS += `pkg-config --cflags sdl2`
LDFLAGS += `pkg-config --libs sdl2`

main:
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -o main

run: main
	./main

clean:
	rm main

.PHONY: run clean
