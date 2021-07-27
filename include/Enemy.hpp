#pragma once
#include "GameObject.hpp"

class Enemy : public GameObject
{
public:
    void load(const SDL_Rect& rect, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();
};