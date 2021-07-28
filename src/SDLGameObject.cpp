#include "SDLGameObject.hpp"

void SDLGameObject::draw()
{
    
    TextureManager::Instance()->drawFrame(textureID,portrait,currentRow,currentFrame,
    Game::Instance()->getRenderer());
};
void SDLGameObject::clean(){};
void SDLGameObject::update(){};

Player::Player(const LoaderParams* pParams)
:SDLGameObject(pParams){
    
    portrait = pParams->getRect();
}


void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    portrait.y++;
    currentFrame =int((SDL_GetTicks()/100)%10);
}
void Player::clean()
{
    
}