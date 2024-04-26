#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "object.h"

#define WIDTH	1280
#define HEIGHT	 720

class game
{
public:

	bool running, fullscreen;
	int frameCount, timerFPS, lastFrame, lastTime, fps;

	//Constructor & Destructor
	game();
	~game();

	//game loop
	void loop();
	void update();
	void input();
	void render();


	//rectangle stuff
	SDL_Rect r;

	//draw an object stuff
	void draw(object o);

	static SDL_Renderer* renderer; // KEEP IT PUBLIC
private:
	SDL_Window* window;
	SDL_Event e;
};

#endif GAME_H

