#include <iostream>

#include "gfxnew.h"



class Invaders{
	public:
		Invaders();
		~Invaders();
		void shoot();
		bool isHit();
		void move(int, int);
	private:
		int x, y;
		int rad1 = 25;
		int rad2 = 30;
		int dx = 1;
};
