#include <SDL2/SDL.h>
#include <stdio.h>
#include "Game.hpp"

int main(int argc, char** args)
{
    if(Game::Instance()->init("Game v1,0",0,0,640,480,0))
    {
        while(Game::Instance()->running())
        {
            Game::Instance()->handleEvents();
            Game::Instance()->update();
            Game::Instance()->render();
            SDL_Delay(10);
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