#include "Enemy.hpp"
void Enemy::load(const SDL_Rect& rect, std::string textureID)
{
    GameObject::load(rect,textureID);
}
void Enemy::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Enemy::update()
{
    portrait.y++;
    portrait.x++;
    currentFrame =int((SDL_GetTicks()/100)%10);
}
void Enemy::clean()
{
    
}