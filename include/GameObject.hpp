#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "TextureManager.hpp"
class GameObject
{
public:
    virtual void load(const SDL_Rect& rect, std::string texID);
    virtual void draw(SDL_Renderer* pRenderer);
    virtual void update();
    virtual void clean();
protected:
    std::string textureID;
    SDL_Rect portrait;
    int currentRow,currentFrame;
};