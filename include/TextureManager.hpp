#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
class TextureManager
{
public:
    static TextureManager* Instance()
    {
        if(instance == 0)
        {
            printf("Texture Manager Instanced!\n");
            instance = new TextureManager();
            return instance;
        }
        return instance;
    }
    bool load(  std::string fileName, std::string id, SDL_Renderer* pRenderer);
    void draw(  std::string id, const SDL_Rect& rect,SDL_Renderer* pRenderer, 
                SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(  std::string id, const SDL_Rect& rect, int currentRow, int currentFrame,
                SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    std::map<std::string,SDL_Texture*> textureMap;
private:
    TextureManager(){};
    static TextureManager* instance;
};