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

class Position
{
    private:
    int _X;
    int _Y;

    public:
    Position();
    int X();
    int Y();
    void X(int X);
    void Y(int Y);
    void Add_X(int X);
    void Add_Y(int Y);
};

class Entity
{
   private:
    int _Height;
    int _Width;
    bool _Show;
    int _Life;
    int _Damage;
    Position _Position;

   public:
    // native
    Entity();
    ~Entity();
    
    // getters / setters
    int Height();
    int Width();
    int Show();
    int Life();
    int Damage();
    class Position Position();
    
    void Position(int x, int y);

    // movement
    int Move(int x, int y);
};

class _SDL_Main
{
    private:
        SDL_Window* Window;
        SDL_Surface* WinSurface;
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
        int CHECK_COLLISION(Entity* Entity);

        void PRINT_SDL_ERROR(string message);
};

#endif