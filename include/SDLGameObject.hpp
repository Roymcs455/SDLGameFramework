#pragma once
#include "Game.hpp"
class SDLGameObject: public GameObject
{
public:
    SDLGameObject(const LoaderParams* pParams)
    :GameObject(pParams){
        printf("SDLGameObject constructor\n");
        portrait = pParams->getRect();
        textureID = pParams->getTextureID();
        currentFrame = 0;
        currentRow = 1;
    };
    virtual void draw();
    virtual void update();
    virtual void clean();
protected:
    SDL_Rect portrait;
    int currentFrame,currentRow;
    std::string textureID;
};
class Player: public SDLGameObject
{
public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};