# Makefile for lab11

fractals: invaders.cpp
	g++ invaders.cpp gfxnew.o -lX11 -o invaders

clean:
	rm invaders

