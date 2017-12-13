# Makefile for lab11

invaderstest: invaderstest.cpp
	g++ -std=c++11 invaderstest.cpp gfxnew.o -lX11 -o invaderstest

clean:
	rm invaderstest
