#ifndef RENDER_H
#define RENDER_H

// DEPENDÊNCIAS
#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>

// DIMENSÕES
#define res_Height (1366)
#define res_Width (976)

// SAÍDAS SIMPLES
#define SUCESS -110
#define FAILURE -111

using namespace std;

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
        void PRINT_SDL_ERROR(string message);
};

#endif