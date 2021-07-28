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
    SDL_Rect src;
    src.x=src.y = 0;
    src.w = rect.w;
    src.h = rect.h;
    SDL_RenderCopyEx(pRenderer, textureMap[id], &src,&rect,0,0,flip);
}
void TextureManager::drawFrame( std::string id, const SDL_Rect& rect, int currentRow,
                                int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect src;
    queryTexture(id,src.w,src.h);
    src.w /= 10;
    src.x = src.w * currentFrame;
    src.y  =src.h * (currentRow-1);
       

    SDL_RenderCopyEx(pRenderer, textureMap[id], &src,&rect,0,0,flip);
}

void TextureManager::queryTexture(std::string texID, int& w, int& h)
{
    SDL_QueryTexture(textureMap[texID],NULL,NULL,&w,&h);
}

TextureManager* TextureManager::instance = 0;