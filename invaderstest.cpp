// Zachary Spitzer and Henri Francois
// Final Project Code
// December 8th, 2017

#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <cmath>

#include "gfxnew.h"
// #include "invaders.h"

using namespace std;
// Segmentation fault (core dumped)

XRectangle shoot( int, int, int, XRectangle &, vector<XRectangle> &);
bool isHit(XRectangle, XRectangle);
void draw_rectangle(XRectangle);

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
	int ds = 10;
	int life = 3;

  XRectangle laser = {x, base, 2, 8};

	XRectangle rect = {width/2, height/2, 100, 50};
	XRectangle rect2 = {width/4, height/2, 100, 50};
	XRectangle rect3 = {width, height/2, 100, 50};
	vector<XRectangle> invaders = {rect, rect2, rect3};


	gfx_open(width,height,"Final Project");
	gfx_color(255,255,255);

	while (c != 'q'){

		// all event updates happen in this part of the loop
		gfx_clear();
		gfx_circle(x + dx, y, offset);
		for (int r = 0; r < invaders.size(); r++){
			draw_rectangle(invaders[r]);
		}
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
					shoot(x, base, ds, laser, invaders);
				}
				else if (c == 's'){
					life = life - 1;
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


void shoot( int a,  int b, int ds, XRectangle laser, vector<XRectangle> &aliens){
	clock_t t;
	t = clock();
	for (int i = 1; i < b/ds; i++){
		gfx_clear();
		// usleep(8000);
		draw_rectangle(laser);
		laser.x = a;
		laser.y -= ds*i;
		for (int it = 0; it <= aliens.size(); ++it){
			auto st = aliens.begin();
			if (isHit(laser, aliens[it]) ){
				aliens.erase(st+it);
				break;
			}
		}
		usleep(15000);
		gfx_flush();
	}
	t = clock() - t;
	float dt = (float)t / CLOCKS_PER_SEC;

	if (dt < 1) usleep(pow(10.0, 3.0) - dt);


	return;
}

// bool isHit(Invader X, XSegment P){
// 	bool hit = false;
// 	if (M.y <= X.rad1 ){
// 		hit = true;
// 	}
//
// 	return hit;
// }

bool isHit(XRectangle M, XRectangle P){
	bool hit = false;
	if ( P.x >= M.x && P.x <= M.x + M.width){
		if (P.y >= M.y && P.y <= M.y + M.height){
				hit = true;
		}
	}

	return hit;
}


void draw_rectangle(XRectangle r)
{
  gfx_line(r.x, r.y, r.x + r.width, r.y);
  gfx_line(r.x + r.width, r.y, r.x + r.width, r.y + r.height);
  gfx_line(r.x + r.width, r.y + r.height, r.x, r.y + r.height);
  gfx_line(r.x, r.y + r.height, r.x, r.y);
}
