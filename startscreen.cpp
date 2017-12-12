// This is just a way of checking to make sure the opening screen works.


#include "gfxnew.h"

int main(){

	int x = 800, y = 800;
	char c;
	
	char thefont[] = "12x24";
	char thefont2[] = "8x16";

	char mytext[] = "Space Invaders";
	char mytext2[] = "Press space to begin.";
	int textw, texth;
 
		gfx_open(x,y,"Start Screen");
		gfx_clear();
		gfx_color(255,255,255);
		gfx_changefont(thefont);
	while (c != 32){

		textw = gfx_textpixelwidth(mytext, thefont);
		texth = gfx_textpixelheight(mytext, thefont);

		gfx_text(300,400,mytext);	

		textw = gfx_textpixelwidth(mytext2, thefont2);
		texth = gfx_textpixelheight(mytext2, thefont2);
		gfx_text(250,600,mytext2);

		gfx_flush();
		c = gfx_wait();
	}
}
