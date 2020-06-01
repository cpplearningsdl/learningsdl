#pragma once
#include "Sdl.h"
#include "Game.h"


class Objects
{
public:
	Objects();

	void totalChange(int t, int m, int x, int y, int h, int w, int txpos, int typos);

	void move();
	void objectrender();
 
	int type;
	int mode;
	int xpos, ypos;
	int height, width;
	int texturexpos, textureypos;

	SDL_Rect srcRect, destRect;

};
