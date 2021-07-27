#pragma once
#include <SDL2/SDL.h>
#include <vector>

#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

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
GameObject* go1;
GameObject* go2;
GameObject* go3;


std::vector<GameObject*> gameObjects;

};