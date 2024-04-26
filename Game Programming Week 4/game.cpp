#include "game.h"
#include <iostream>
#include "object.h"
#include <SDL_image.h>

object* player = new object();


SDL_Renderer* game::renderer = nullptr;


game::game()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//initialise SDL_image to support PNG
	int imgFlags = IMG_INIT_PNG;
	int imgInitResult = IMG_Init(imgFlags);
	
	if ((imgInitResult & imgFlags) != imgFlags) //error handling for image init
	{
		printf("Image init failed: ", SDL_GetError());
		return;
	}

	else
	{
		printf("image initialised \n");
	}

	running = true;

	window = SDL_CreateWindow("Henry Ball, CGP2015M, 26598617, *GAME NAME*", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	if (!window)
	{
		printf("Window Error: \n", SDL_GetError());
	}

	else 
	{
		printf("Window Created \n");
	}

	if (!renderer)
	{
		printf("Renderer Error: \n", SDL_GetError());
	}
	else
	{
		printf("Renderer Created \n");
	}

	player->SetImage("assets/player.png", renderer);
	player->setDest(640, 620, 500, 500);

	if (player)
	{
		printf("player image created");
	}

	loop();
}

game::~game()
{
	running = false;
	SDL_Quit();
}

void game::update()
{
	if (fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	if (!fullscreen) SDL_SetWindowFullscreen(window, 0);

}

void game::input()
{
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) running = false;
	}

	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	if (keystates[SDL_SCANCODE_ESCAPE]) running = false;
	if (keystates[SDL_SCANCODE_F11]) fullscreen = !fullscreen;
	
	if (keystates[SDL_SCANCODE_A])
	{
		//std::cout << "i work";
		r.x = r.x - 5;
		printf("A key Pressed \n");
	}

	if (keystates[SDL_SCANCODE_D])
	{
		//std::cout << "i work";
		r.x = r.x + 5;
		printf("D  key Pressed \n");
	}
}

void game::render()
{

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);


	SDL_RenderDrawRect(renderer, &r);
	


	player->render(renderer);
	

	frameCount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000 / 60)) //sets frames to 60
	{
		SDL_Delay((1000 / 60) - timerFPS);
	}

	SDL_RenderPresent(renderer);
}

void game::draw(object o)
{
	SDL_Rect dest = o.getDest();
	SDL_Rect source = o.getSource();
	SDL_RenderCopyEx(renderer, o.getTex(), &source, &dest, 0, NULL, SDL_FLIP_NONE);
}

void game::loop()
{
	r.x = 640;
	r.y = 620;
	r.w = 50;
	r.h = 50;

	while (running) 
	{
		lastFrame = SDL_GetTicks();
		if (lastFrame >= (lastTime + 1000)) {
			lastTime = lastFrame;
			fps = frameCount;
			frameCount = 0;
		}

		//std::cout << fps << std::endl;

		update();
		input();
		render();


	}


}