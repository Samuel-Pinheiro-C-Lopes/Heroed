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

#define iplayer -10
#define imonster -11
#define iground -20
#define iterrain -21

using namespace std;

class Terrain
{
    private:
        int _X;
        int _Y;
        int _Content;
    public:
        int X();
        int Y();
        int Content();  
};

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
    int _Type;

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
    int Type();
    class Position Position();
    
    void Position(int x, int y);

    bool CheckCollision(Primary& p);

    // movement
    int Move(int x, int y, Primary& p);
};

class Primary
{
    private:
        SDL_Window* Window;
        SDL_Surface* WinSurface;
        int Height;
        int Width;
        Terrain** WinGrid;

    public:
        // native
        Primary();
        ~Primary();
        
        // base
        int START();
        int END();
        
        // grid
        int SET_GRID();
        bool CHECK_COLLISION(Entity* Entity);
        bool UPDATE_GRID(Entity* Entity);

        void PRINT_SDL_ERROR(string message);

        friend class Entity;
};

#endif