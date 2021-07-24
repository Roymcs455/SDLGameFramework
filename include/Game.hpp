#pragma once
#include <SDL2/SDL.h>
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

SDL_Texture* tex;
SDL_Rect src, dest;

};