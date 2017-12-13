#include <iostream>
#include <cmath>

#include "gfxnew.h"

using namespace std;

Invader::Invader(){
  gfx_ellipse(x, y, rad1, rad2);
}

Invader::~Invader(){
}
  
