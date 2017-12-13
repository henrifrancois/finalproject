// Zachary Spitzer
// Final Project Code
// December 8th, 2017

#include <iostream>
#include "gfxnew.h"
#include <ctime>
#include <unistd.h>
using namespace std;
// Segmentation fault (core dumped)

void shoot(int, int, int);

int main(){

	char c;
	int x = 250;
	int y = 250;
	int base = y - 20;
	int dx = 0;
	int dy = 0;
	int ds = 5;
	int life = 3;
	gfx_open(500,500,"Final Project");
	gfx_color(255,255,255);
	while (c != 'q'){
		gfx_clear();
		gfx_circle(x + dx, y + dy, 20);
		if (c == ' '){
			shoot(x, base, ds);
			base -= ds;
			usleep(3000);
		}
		gfx_flush();
		usleep(2000);
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
			else if (c == ' '){
				base = y - 20;
			}
			else if (c == 's'){
				life = life - 1;
				usleep(200000);
				if(life == 2) gfx_color(0,0,255);
				else if(life == 1) gfx_color(255,0,0);
				else if(life == 0) return 0;
			}
		}
		else if(gfx_event_waiting() == 0 || gfx_event_waiting() == 2){
			dx = 0;
			dy = 0;
			// ds = 0;
		}
	}
}


void shoot(int x, int y, int ds){
	gfx_line(x, y, x, y - ds);
}
