#include <SDL2/SDL.h>
#include "Game.hpp"


int main(int argc, char** args)
{
    Game juego;
    juego.init("Game v1,0",0,0,640,480,0);
    while(juego.running())
    {
        juego.handleEvents();
        juego.update();
        juego.render();
    }
    juego.clean();
    return 0;
}