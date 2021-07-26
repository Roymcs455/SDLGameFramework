#pragma once
#include "GameObject.hpp"


class Player: public GameObject
{
    void draw();
    void update();
    void clean();
};