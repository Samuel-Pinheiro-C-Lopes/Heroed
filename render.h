#ifndef RENDER_H
#define RENDER_H

// DEPENDÊNCIAS
#include <SDL2/SDL.h>
#include <iostream>

// DIMENSÕES
#define res_Height (1366)
#define res_Width (976)

// SAÍDAS SIMPLES
#define SUCESS -110
#define FAILURE -111

using namespace std;

class _SDL_Entity
{
   private:
    int height;
    int width;
    bool show;
   public:
    // native
    _SDL_Entity();
    ~_SDL_Entity();
    
    // getters / setters
    int Get_Height();
    int Get_Width();
    void Set_Width(int width);
    void Set_Height(int height);
    
    // movement
    int Move();
};

class _SDL_Main
{
    private:
        SDL_Window* window;
        SDL_Surface* win_surface;
        int height;
        int width;
        int** win_grid;
    public:
        // native
        _SDL_Main();
        ~_SDL_Main();
        
        // base
        int START();
        int END();
        
        // grid
        int SET_GRID();
        int CHECK_COLLISION(_SDL_Entity* Entity);

        void PRINT_SDL_ERROR(string message);
};

#endif