// Zachary Spitzer and Henri Francois
// Final Project Code
// December 8th, 2017

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <cmath>

#include "gfxnew.h"

using namespace std;
// Segmentation fault (core dumped)

void shoot(int, int, int);

const int width = 500;
const int height = 850;

int main(){

	char c;
	int event;
	int margin = 30;
	int x = width/2;
	int y = (7*height)/10;
	int offset = 20;
	int base = y - offset;
	int dx = 0;

	int dy = 0;
	int ds = 30;
	int life = 3;


	gfx_open(width,height,"Final Project");
	gfx_color(255,255,255);

	while (c != 'q'){

		// all event updates happen in this part of the loop
		gfx_clear();
		gfx_circle(x + dx, y, offset);
		// gfx_rectangle(x, height/2, 50, 70);
		gfx_flush();
		usleep(5000);
		//
		event = gfx_event_waiting();
		if(event){
			c = gfx_wait();
			if (event == 1){
				if (c == 'Q'){
					dx = -5;
					x += dx;
				}
				else if (c == 'S'){
					dx = 5;
					x += dx;
				}
				else if (c == ' '){
					usleep(3000);
					shoot(x, base, ds);
				}
				else if (c == 's'){
					life = life - 1;
					usleep(2000000);
					if(life == 2) gfx_color(0,0,255);
					else if(life == 1) gfx_color(255,0,0);
					else if(life == 0) return 0;
				}
				else{
					continue;
				}
			}
			else if (event == 2){
				continue;
			}
		}
		else{
				dx = 0;
		}
	}
	return 0;
}


void shoot(int x, int y, int ds){
	clock_t t;
	t = clock();
	for (int i = 1; i < y/ds; i++){
		gfx_clear();
		// usleep(8000);
		gfx_line( x, y - ds*i, x, y - ds*(i + 1) );
		usleep(15000);
		gfx_flush();
	}
	t = clock() - t;
	float dt = (float)t / CLOCKS_PER_SEC;

	if (dt < 1) usleep(pow(10.0, 3.0) - dt);

}
