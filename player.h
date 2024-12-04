#ifndef PLAYER_H
#define  PLAYER_H

#include "render.h"

#ifdef RENDER_H

class _Player : _SDL_Entity
{
    private:
        int Life;
        int Damege;
    public:
        // native
        _Player();
        ~_Player();

        // getters / setters
        int Get_Life();
        int Get_Damage();
        void Set_Life();
        void Set_Damage();
};

#endif


#endif