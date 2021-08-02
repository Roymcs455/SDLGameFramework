#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "Vector2D.hpp"
class LoaderParams
{
public:
    LoaderParams(const SDL_Rect& rect, std::string texID):
    size(rect), textureID(texID)
    {
        pos = {0,0};
        vel = {0,0};
        acc = {0,0};
    };
    SDL_Rect getRect() const {return size;};
    std::string getTextureID() const {return textureID;};

private:
    Vector2D pos;
    Vector2D vel;
    Vector2D acc;
    SDL_Rect size;
    std::string textureID;
};