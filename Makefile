# Makefile for lab11

invaderstest: invaderstest.cpp
	g++ invaderstest.cpp gfxnew_restrictive.o -lX11 -o invaderstest

clean:
	rm invaderstest
