#include "render.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>

_SDL_Main::_SDL_Main()
{
    this->window = NULL;
    this->win_surface = NULL;
    this->height = res_Height;
    this->width = res_Width;

    this->win_grid = (int**) malloc(sizeof(int*) * this->height);

    for (int i = 0; i < this->width; i++)
        this->win_grid[i] = (int*) malloc(sizeof(int) * this->height);
}

_SDL_Main::~_SDL_Main()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}