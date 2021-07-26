#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "TextureManager.hpp"
class GameObject
{
public:
    void load(const SDL_Rect& rect, std::string texID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
protected:
    std::string textureID;
    SDL_Rect portrait;
    int currentRow,currentFrame;

};
class Player: public GameObject
{
    void draw();
    void update();
    void clean();
};