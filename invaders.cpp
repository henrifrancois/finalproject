// Zachary Spitzer
// Final Project Code
// December 8th, 2017

#include <iostream>
#include "gfxnew.h"
#include <ctime>
#include <unistd.h>
using namespace std;
// Segmentation fault (core dumped)
int main(){

	char c;
	int x = 250;
	int y = 250;
	int dx = 0;
	int dy = 0;
	gfx_open(500,500,"Final Project");
	gfx_color(255,0,0);
	while (c != 'q'){
		gfx_clear();
		gfx_circle(x + dx, y + dy, 20);
		gfx_flush();
		usleep(1000);
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
			else if (c == 'R'){
				dy = -5;
				y += dy;
			}
			else if (c == 'T'){
				dy = 5;
				y += dy;
			}
		}
		else if(gfx_event_waiting() == 0 || gfx_event_waiting() == 2){
			dx = 0;
			dy = 0;
		}

	}
}
