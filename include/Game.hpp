#pragma once
#include <SDL2/SDL.h>
#include <vector>

#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "SDLGameObject.hpp"

class Game 
{
public:
    static Game* Instance()
    {
        if(gameInstance == NULL)
        {
            gameInstance = new Game();
            return gameInstance;
        }
        return gameInstance;
    }
    bool init(const char* title, int xpos, int ypos, int height,int width, int flags);
    void update();
    void render();
    void handleEvents();
    void clean();
    bool running();
    SDL_Renderer* getRenderer() const {return gameRenderer;};
private:
    Game(){};
    bool isRunning;
    int screenWidth,screenHeight;
    SDL_Renderer* gameRenderer;
    SDL_Window* gameWindow;
    int currentFrame;
    int currentRow;

    static Game* gameInstance;

    std::vector<GameObject*> gameObjects;

};