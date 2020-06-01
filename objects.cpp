#include "Objects.h"
 
 


Objects::Objects()
{
	type = 1;
	mode = 0;
	xpos = 0;
	ypos = 0;
	height = 32;
	width = 32;
	texturexpos = 0;
	texturexpos = 0;

	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = texturexpos;
	srcRect.y = textureypos;
	destRect.h = height;
	destRect.w = width;
	destRect.x = xpos;
	destRect.y = ypos;

}

void Objects::totalChange(int t, int m, int x, int y, int h, int w, int txpos, int typos)
{
	type = t;
	mode = m;
	xpos = x;
	ypos = y;
	height = h;
	width = w;
	texturexpos = txpos;
	texturexpos = typos;

	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = texturexpos;
	srcRect.y = textureypos;
	destRect.h = height;
	destRect.w = width;
	destRect.x = xpos;
	destRect.y = ypos;
}

void Objects::move()
{

}

void Objects::objectrender()
{
	SDL_RenderCopy(Game::renderer, Game::sheet, &srcRect, &destRect);
	std::cout << type << std::endl;

}
