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
                printf("Renderer created succesfully!\n");
                isRunning = true;
            }
        }
    }
    return isRunning;
}
void Game::render()
{
    SDL_SetRenderDrawColor(gameRenderer,255,255,255,255);
    SDL_RenderClear(gameRenderer);
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