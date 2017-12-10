#include <iostream>

#include "gfxnew.h"



class Invader{ 
	public:
		void shoot();
		void increaseSpeed();
		void draw();
	private:
		int x, y;
		int width, height;
};
