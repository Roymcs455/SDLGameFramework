#include "TextureManager.hpp"

bool TextureManager::load(std::string fileName,std::string id, SDL_Renderer* pRenderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
    if(tempSurface == 0)
    {
        return false;
    }

    SDL_Texture* pTex = SDL_CreateTextureFromSurface(pRenderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if(pTex != NULL)
    {
        textureMap[id] = pTex;
        return true;
    }
    printf("Couldn't load %s, SDL_Error: %s, IMG_Error: %s",fileName.c_str(),SDL_GetError(), IMG_GetError());
    return false;

}
void TextureManager::draw(std::string id,const SDL_Rect& rect, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect dest;
    dest.x=dest.y = 0;
    dest.w = rect.w;
    dest.h = rect.h;
    SDL_RenderCopyEx(pRenderer, textureMap[id], &rect,&dest,0,0,flip);
}
void TextureManager::drawFrame( std::string id, const SDL_Rect& rect, int currentRow,
                                int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect src;
    src.x = rect.w * currentFrame;
    src.y  =rect.h * (currentRow-1);
    src.w = rect.w;
    src.h = rect.h;
       

    SDL_RenderCopyEx(pRenderer, textureMap[id], &src,&rect,0,0,flip);
}
TextureManager* TextureManager::instance = 0;