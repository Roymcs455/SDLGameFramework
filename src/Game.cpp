#include "Game.hpp"

bool Game::init(const char* title, int xpos, int ypos, int width,int height, int flags)
{
    screenHeight=height;
    screenWidth=width;
    isRunning = false;
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {

        gameWindow = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        if(gameWindow == NULL)
        {
            printf("failed to create a window! SDL_Error: %s\n",SDL_GetError());
            return isRunning;
        }
        else
        {
            gameRenderer = SDL_CreateRenderer(gameWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
            if(gameRenderer != NULL)
            {
                SDL_SetRenderDrawColor(gameRenderer,255,0,255,255);
                printf("Renderer created succesfully!\n");
                isRunning = true;
            }
        }
    }

    SDL_Surface* tempSurf = SDL_LoadBMP("res/graphics/character1.bmp");
    tex = SDL_CreateTextureFromSurface(gameRenderer, tempSurf);
    if(tex == NULL)
        printf("tex is null\n");
    else
        printf("tex is not null\n");
    SDL_FreeSurface(tempSurf);
    SDL_QueryTexture(tex,NULL,NULL,&src.w,&src.h);
    src.x= dest.x = src.y = dest.y = 0;
    dest.w = src.w;
    dest.h = src.h;
    printf("x: %d, y: %d, w: %d, h: %d\n",src.x,src.y,src.h,src.h);

    return isRunning;
}
void Game::render()
{
    SDL_RenderClear(gameRenderer);
    SDL_RenderCopy(gameRenderer,tex,&src,&dest);

    SDL_RenderPresent(gameRenderer);
}
void Game::update()
{

}
void Game::handleEvents()
{
    SDL_Event e;
    if(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}
void Game::clean()
{
    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(gameWindow);
    SDL_Quit();
    printf("Game closed\n");
}
bool Game::running()
{
    return isRunning;
}