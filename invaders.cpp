#include <iostream>
#include <cmath>

#include "gfxnew.h"
#include "invaders.h"

using namespace std;

Invaders::Invaders(){
  gfx_ellipse(x, y, rad1, rad2);
}

Invaders::~Invaders(){
}

void Invaders::move(int u, int v){
		if(u + rad1 + dx > 500 || u - rad1 + dx < 0){
			dx *= -1;
			v += 35;
			gfx_ellipse(u,v,rad1,rad2);
		}
		else{
			u += dx;
			gfx_ellipse(u,v,rad1,rad2);
		}
}

void Invaders::shoot(){
}

bool isHit(){
return true;
}
  
