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
    currentFrame = 0;
    currentRow = 1;
    TextureManager::Instance()->load("res/graphics/char.png","animated",gameRenderer);

    gameObjects.push_back(new Player(new LoaderParams(SDL_Rect({0,32,16,16}),"animated")));
    return isRunning;
}
void Game::render()
{
    SDL_RenderClear(gameRenderer);
    /* TextureManager::Instance()->draw("animated",SDL_Rect({0,0,160,16}),gameRenderer);
    TextureManager::Instance()->drawFrame("animated",SDL_Rect({16,16,16,16}),currentRow,currentFrame,gameRenderer);

 */
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }

    SDL_RenderPresent(gameRenderer);
}
void Game::update()
{
    currentFrame = int((SDL_GetTicks()/100)%10);
    for(std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
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
Game* Game::gameInstance = 0;