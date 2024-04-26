#include "object.h"

void object::render(SDL_Renderer* ren)
{
	SDL_Rect dest = getDest();
	SDL_Rect src = getSource();
	SDL_RenderCopyEx(ren, tex, &src, &dest, NULL, NULL, SDL_FLIP_NONE);
	//SDL_RenderCopy(ren, tex, &src, &dest);
}

void object::setDest(int x, int y, int w, int h)
{
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
		
}
void object::setSource(int x, int y, int w, int h)
{
	source.x = x;
	source.y = y;
	source.w = w;
	source.h = h;

}
void object::SetImage(std::string fileName, SDL_Renderer* ren)
{
	SDL_Surface* surf = IMG_Load(fileName.c_str());
	if (!surf) 
	{
		printf("Error loading image: ", IMG_GetError());
		return;
	}
	tex = SDL_CreateTextureFromSurface(ren, surf);
	SDL_FreeSurface(surf);
}