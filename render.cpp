#include "render.h"

#pragma region SDL_MAIN

_SDL_Main::_SDL_Main()
{
    this->Window = NULL;
    this->WinSurface = NULL;
    this->height = res_Height;
    this->width = res_Width;

    this->win_grid = (int**) malloc(sizeof(int*) * this->height);

    for (int i = 0; i < this->width; i++)
        this->win_grid[i] = (int*) malloc(sizeof(int) * this->height);
}

int _SDL_Main::START()
{
    // initializates the SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        this->PRINT_SDL_ERROR("INITIALIZATION FAILED");
        return FAILURE;
    }

    // creates the window
    this->Window = SDL_CreateWindow("Main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);

    // verify if the window was created successfully
    if (!Window)
    {
        this->PRINT_SDL_ERROR("WINDOW CREATION FAILED");
        return FAILURE;
    }

    // gets the surface of the window
    this->WinSurface = SDL_GetWindowSurface(this->Window);

    // verify if the surface was obtained successfully
    if (!WinSurface)
    {
        this->PRINT_SDL_ERROR("SURFACE OBTAINMENT FAILED");
        return FAILURE;
    }

    return SUCESS;
}

int _SDL_Main::END()
{
    // Destroy memory allocations
    SDL_DestroyWindow(this->Window); // window

    // Quit SDL
    SDL_Quit();

    return SUCESS;
}

void _SDL_Main::PRINT_SDL_ERROR(string message) // 
{
    cout << message << ": " << SDL_GetError() << endl;
    system("read");
}

_SDL_Main::~_SDL_Main()
{
    this->END();
}

#pragma endregion

#pragma region ENTITY

////////////////////////////////////////////

int Entity::Height()
{
    return this->_Height;
}

int Entity::Width()
{
    return this->_Width;
}

Position Entity::Position()
{
    return this->_Position;
}

void Entity::Position(int X, int Y)
{
    this->_Position.X(X);
    this->_Position.Y(Y);
}

////////////////////////////////////////////////

int Entity::Move(int X, int Y)
{
    this->_Position.Add_X(X);
    this->_Position.Add_Y(Y);
}

#pragma endregion

#pragma region POSITION

int Position::X()
{
    return this->_X;
}

int Position::Y()
{
    return this->_Y;
}

void Position::X(int X)
{
    this->_X += X;
}

void Position::Y(int Y)
{
    this->_Y += Y;
}

#pragma endregion