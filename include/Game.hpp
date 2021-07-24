#pragma once
#include <SDL2/SDL.h>
class Game 
{
public:
    Game();
protected:
private:
int screenWidth,screenHeight;
SDL_Renderer* gameRenderer;
SDL_Window* gameWindow;
};