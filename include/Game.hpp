#pragma once
#include <SDL2/SDL.h>
#include "TextureManager.hpp"
class Game 
{
public:
    Game(){};
    bool init(const char* title, int xpos, int ypos, int height,int width, int flags);
    void update();
    void render();
    void handleEvents();
    void clean();
    bool running();
private:
bool isRunning;
int screenWidth,screenHeight;
SDL_Renderer* gameRenderer;
SDL_Window* gameWindow;
int currentFrame;
int currentRow;
TextureManager texMan;
SDL_Rect src, dest;

};