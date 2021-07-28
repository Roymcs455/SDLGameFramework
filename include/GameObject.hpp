#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "LoaderParams.hpp"
class GameObject
{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
protected:
    GameObject(const LoaderParams* pParams){};
    virtual ~GameObject(){}
};
