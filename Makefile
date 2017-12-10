# Makefile for lab11

invaderstest: invaderstest.cpp
	g++ invaderstest.cpp gfxnew.o -lX11 -o invaderstest

clean:
	rm invaderstest