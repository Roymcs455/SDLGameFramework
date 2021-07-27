#pragma once
#include "GameObject.hpp"


class Player: public GameObject
{
public:
    void load(const SDL_Rect& rect, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
};