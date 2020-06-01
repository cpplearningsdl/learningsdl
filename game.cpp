#include "Game.h"
 

SDL_Renderer* Game::renderer = nullptr;
SDL_Texture* Game::sheet = nullptr;
SDL_Texture* Game::background = nullptr;
Objects* myobjects;
 

Game::Game() {}

Game::~Game() {}

void Game::initialize(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	//check full screen
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//make window
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "sdl initialized" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "made window" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
	
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "made renderer" << std::endl;
		}
		isrunning = true;

		//load sheet
		SDL_Surface* tempSurface = IMG_Load("sheet.png");
		sheet = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);

		tempSurface = IMG_Load("background.png");
		background = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
 

	}
	  
}


void Game::doevents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isrunning = false;
		break;
	default:
		break;
	}
}
 
void Game::logic()
{
	//player->Update();
	//background->Update();
}

void Game::loadlevel(int lvl)
{
	myobjects = new Objects();
	std::cout << "spawnedobjects" << std::endl;
}


void Game::render()
{
  
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, background, NULL, NULL);
 
		myobjects->objectrender();
 
		SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "quit SDL" << std::endl;


}

bool Game::running() { return isrunning; }
