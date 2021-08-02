#include <SDL2/SDL.h>
#include <stdio.h>
#include "Game.hpp"

#define FPS 60
const int  DELAY_TIME = 1000.0f/FPS;
int main(int argc, char** args)
{
    Uint32 frameStart,frameTime;
    if(Game::Instance()->init("Game v1,0",0,0,640,480,0))
    {
        while(Game::Instance()->running())
        {
            frameStart = SDL_GetTicks();
            Game::Instance()->handleEvents();
            Game::Instance()->update();
            Game::Instance()->render();
            SDL_Delay(10);
            frameTime = SDL_GetTicks()-frameStart;
            if(frameTime < DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME-frameTime));
            }
        }
    }
    else
    {
        printf("Game initialization failed: SDL_Error: %s \n",SDL_GetError());
        return -1;
    }
    printf("Closing Game...\n");
    Game::Instance()->clean();
    return 0;
}