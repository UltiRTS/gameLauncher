
SDLFLAGS=$(shell sdl2-config --cflags --libs)
CPPFLAGS=-Wall

.PHONY: all clean

all: launcher

launcher:
	g++ -o $@.exe launcher.cpp $(CPPFLAGS) $(SDLFLAGS) -lSDL2_test

clean:
	rm ./launcher
