// Zachary Spitzer and Henri Francois
// Final Project Code
// December 8th, 2017

#include <iostream>
#include "gfxnew.h"
#include <ctime>
#include <unistd.h>
using namespace std;
// Segmentation fault (core dumped)

void shoot(int, int, int);

const int width = 500;
const int height = 850;

int main(){

	char c;
	int margin = 30;
	int x = width/2;
	int y = height - 2*margin;
	int offset = 20;
	int base = y - offset;
	int dx = 0;
	int ds = 0;

	//
	gfx_open(width,height,"Final Project");
	gfx_color(255,0,0);

	//
	while (c != 'q'){

		// all event updates happen in this part of the loop
		gfx_clear();
		gfx_circle(x + dx, y, offset);
		gfx_rectangle(x, height/2, 50, 70);
		gfx_flush();
		usleep(1000);
		//
		if(gfx_event_waiting()){
			c = gfx_wait();
			if (c == 'Q'){
				dx = -5;
				x += dx;
			}
			else if (c == 'S'){
				dx = 5;
				x += dx;
			}
			else if (c == ' '){
				ds += 5;
				shoot(x, base, ds);
			}
			else{
				continue;
			}
		}
		else if(gfx_event_waiting() == 0 || gfx_event_waiting() == 2){
			dx = 0;
			ds = 0;
		}
	}
}


void shoot(int x, int y, int ds){
	for (int i = 0; i < y/ds; i++){
		// gfx_clear();
		gfx_line( x, y - ds*i, x, y - ds*(i + 1) );
		// gfx_flush();
		// usleep(10000);
	}
}
