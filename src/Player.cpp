#include "Player.hpp"

void Player::load(const SDL_Rect& rect, std::string texID)
{
    GameObject::load(rect,texID);
}
void Player::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Player::update()
{
    portrait.y++;
    currentFrame =int((SDL_GetTicks()/100)%10);
}
void Player::clean()
{
    
}