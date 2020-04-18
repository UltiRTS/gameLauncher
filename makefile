
SDLFLAGS=$(shell sdl2-config --cflags --libs)
CPPFLAGS=-Wall

.PHONY: all clean

all: launcher

launcher:
	g++ -o $@.exe launcher.cpp -I/usr/local/include -L/usr/local/lib -lSDL2 -lSDL2_test

clean:
	rm ./launcher
