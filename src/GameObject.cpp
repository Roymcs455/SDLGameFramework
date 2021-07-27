#include "GameObject.hpp"

void GameObject::load(const SDL_Rect& rect, std::string texID)
{
    portrait = rect;
    textureID = texID;
    currentFrame = currentRow = 1;
}
void GameObject::draw(SDL_Renderer* pRenderer)
{
    TextureManager::Instance()->drawFrame(textureID,portrait, currentRow,currentFrame, pRenderer);
}
void GameObject::update()
{
    portrait.x++;
    currentFrame= int((SDL_GetTicks()/100)%10);
}
void GameObject::clean()
{
    
}
