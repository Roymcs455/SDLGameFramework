#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class LTexture
{
public:
    LTexture();
    bool loadFromFile(std::string path);
    void free();
    //void render();
    int getWidth();
    int getHeight();
    bool isAnimated();
    int getRows();
    int getFrames();
    int getDimentions();
private:
    SDL_Texture* tex;
    SDL_Rect dimentions;
    int rows;
    int frames;


};