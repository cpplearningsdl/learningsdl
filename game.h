#include "SDL_Image.h"
#include "Objects.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();


	void initialize(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void doevents();
	void logic();
	void render();
	void clean();
	void loadlevel(int lvl);

	bool running( );

	static SDL_Renderer *renderer;
	static SDL_Texture *sheet;
	static SDL_Texture *background;

 

private:
	bool isrunning;
	SDL_Window *window;



};
