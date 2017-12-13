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
	int x = 250;
	int y = 250;
	int x2 = 0;
	int x3 = 50;
	int y2 = 100;
	int y3 = 150;
	int base = y - 20;
	int margin = 30;
	int dx = 0;

	int dy = 0;
	int dx2 = 1;
	int ds = 5;
	int life = 3;


	gfx_open(width,height,"Final Project");
	gfx_color(255,255,255);

	while (c != 'q'){

		// all event updates happen in this part of the loop
		gfx_clear();
		gfx_circle(x + dx, y + dy, 20);
	        if (x3 + dx2 > 500 || x2 + dx2 < 0){
        	        dx2 *= -1;
			y2 += 35;
			y3 += 35;
               		gfx_line(x2,y2,x2,y3);
                	gfx_line(x2,y3,x3,y3);
               	 	gfx_line(x3,y3,x3,y2);
               		gfx_line(x3,y2,x2,y2);
        	}
        	else{
                	x2 += dx2;
                	x3 += dx2;
                	gfx_line(x2,y2,x2,y3);
                	gfx_line(x2,y3,x3,y3);
                	gfx_line(x3,y3,x3,y2);
                	gfx_line(x3,y2,x2,y2);
        }

		if (c == ' '){
			shoot(x, base, ds);
			base -= ds;
			usleep(3000);
		}
		gfx_flush();
		usleep(5000);
		//
		if(gfx_event_waiting() > 0 || gfx_event_waiting() < 2){
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
		usleep(8000);
		gfx_line( x, y - ds*i, x, y - ds*(i + 1) );
		usleep(30000);
		gfx_flush();
	}
	t = clock() - t;
	float dt = (float)t / CLOCKS_PER_SEC;

	if (dt < 1) usleep(pow(10.0, 3.0) - dt);

}
