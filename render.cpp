#include "render.h"

#pragma region SDL_MAIN

Primary::Primary()
{
    this->Window = NULL;
    this->WinSurface = NULL;
    this->Height = res_Height;
    this->Width = res_Width;

    this->WinGrid = (Terrain**) malloc(sizeof(Terrain*) * this->Height);

    for (int i = 0; i < this->Width; i++)
        this->WinGrid[i] = (Terrain*) malloc(sizeof(Terrain) * this->Height);
}

int Primary::START()
{
    // initializates the SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        this->PRINT_SDL_ERROR("INITIALIZATION FAILED");
        return FAILURE;
    }

    // creates the window
    this->Window = SDL_CreateWindow("Main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->Width, this->Height, SDL_WINDOW_SHOWN);

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

int Primary::END()
{
    // Destroy memory allocations
    SDL_DestroyWindow(this->Window); // window

    // Quit SDL
    SDL_Quit();

    return SUCESS;
}

void Primary::PRINT_SDL_ERROR(string message) // 
{
    cout << message << ": " << SDL_GetError() << endl;
    system("read");
}

Primary::~Primary()
{
    this->END();
}

bool Primary::CHECK_COLLISION(Entity* Entity)
{
    for (int i = Entity->Position().X(); i < Entity->Position().X() + Entity->Width(); i++)
        for (int j = Entity->Position().Y(); i < Entity->Position().Y() + Entity->Height(); i++)
            if (WinGrid[i][j].Content() == iterrain || WinGrid[i][j].Content() == imonster)
                return false;

    return true;
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

int Entity::Type()
{
    return this->_Type;
}

void Entity::Position(int X, int Y)
{
    this->_Position.X(X);
    this->_Position.Y(Y);
}

////////////////////////////////////////////////

int Entity::Move(int X, int Y, Primary& p)
{
    this->_Position.Add_X(X);
    this->_Position.Add_Y(Y);
    if (this->CheckCollision(p))
        p.UPDATE_GRID(this);
    else
        return FAILURE;

    return SUCESS;
}

bool Entity::CheckCollision(Primary& p)
{
    return p.CHECK_COLLISION(this);
}

////////////////////////////////


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