#ifndef OBJECT_H
#define OBJECT_H

#include "SDL.h"
#include "SDL_image.h"
#include <string> // Include <string> for using string data type

class object
{
public:
    
    object() {};
    SDL_Rect getDest() const { return dest; }
    SDL_Rect getSource() const { return source; } 
    SDL_Texture* getTex() const { return tex; }
    void setDest(int x, int y, int w, int h); 
    void setSource(int x, int y, int w, int h); 
    void SetImage(std::string fileName, SDL_Renderer* ren);
    void render(SDL_Renderer* ren);

private:
    SDL_Rect dest = {0, 0, 0, 0,};
    SDL_Rect source = {0, 0, 0, 0};
    SDL_Texture* tex = nullptr;
};

#endif //OBJECT_H

