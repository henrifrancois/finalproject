#include <iostream>

#include "gfxnew.h"



class Invader{
	public:
		Invader();
		~Invader();
		void shoot();
		void increaseSpeed();
		void draw();
		bool hasHit();
		bool isHit();
	private:
		int x, y;
		int rad1, rad2;
		int dx, dy;
};
