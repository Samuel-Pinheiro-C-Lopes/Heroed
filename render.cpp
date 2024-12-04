#include "render.h"

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

int _SDL_Main::START()
{
    // initializates the SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        this->PRINT_SDL_ERROR("INITIALIZATION FAILED");
        return FAILURE;
    }

    // creates the window
    this->window = SDL_CreateWindow("Main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);

    // verify if the window was created successfully
    if (!window)
    {
        this->PRINT_SDL_ERROR("WINDOW CREATION FAILED");
        return FAILURE;
    }

    // gets the surface of the window
    this->win_surface = SDL_GetWindowSurface(this->window);

    // verify if the surface was obtained successfully
    if (!win_surface)
    {
        this->PRINT_SDL_ERROR("SURFACE OBTAINMENT FAILED");
        return FAILURE;
    }

    return SUCESS;
}

int _SDL_Main::END()
{
    // Destroy memory allocations
    SDL_DestroyWindow(this->window); // window

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