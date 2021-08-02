#include "SDLGameObject.hpp"

void SDLGameObject::draw()
{
    
    TextureManager::Instance()->drawFrame(textureID,portrait,currentRow,currentFrame,
    Game::Instance()->getRenderer());
};
void SDLGameObject::clean(){};
void SDLGameObject::update(){
    portrait.x = (int)position.getX();
    portrait.y = (int)position.getY();
};

Player::Player(const LoaderParams* pParams)
:SDLGameObject(pParams){
    portrait = pParams->getRect();
    position = {(float)portrait.x,(float)portrait.y};
    velocity = {0.5,0.5};
    acceleration = {0,0.01};
}


void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    velocity += acceleration;
    position += velocity;
    currentFrame =int((SDL_GetTicks()/50)%10);
    
    SDLGameObject::update();
}
void Player::clean()
{
    
}