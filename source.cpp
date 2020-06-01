#include <SDL.h>
 
#include <stdio.h>
#include <string>

#include "Game.h"

Game *game = nullptr;

int main(int argc, char* args[])
{
	const int FPS = 60;
	const int FRAMEDELAY = 1000 / FPS;

	Uint32 framestart;
	int frametime;

	 
	game = new Game();

	game->initialize("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	game->loadlevel(1);

	while (game->running())
	{
		framestart = SDL_GetTicks();

		//mainloop
		game->doevents();
		game->render();

		frametime = SDL_GetTicks() - framestart;

		if (FRAMEDELAY > frametime)
		{
			SDL_Delay(FRAMEDELAY - frametime);
		}
	}


	game->clean();
	delete game;

	return 0;
}
