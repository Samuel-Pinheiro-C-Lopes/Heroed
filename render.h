#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>

#define res_Height (1366)
#define res_Width (976)

class _SDL_Main
{
    private:
        SDL_Window* window;
        SDL_Surface* win_surface;
        int height;
        int width;
        int** win_grid;
    public:
        _SDL_Main();
        ~_SDL_Main();
        int START();
        int END();
};

#endif