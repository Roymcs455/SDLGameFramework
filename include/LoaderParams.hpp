#pragma once
#include <SDL2/SDL.h>
#include <string>
class LoaderParams
{
public:
    LoaderParams(const SDL_Rect& rect, std::string texID):
    size(rect), textureID(texID)
    {

    };
    SDL_Rect getRect() const {return size;};
    std::string getTextureID() const {return textureID;};

private:

    SDL_Rect size;
    std::string textureID;
};