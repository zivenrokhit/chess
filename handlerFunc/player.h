#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"

class Player {
    friend class Game;
    protected:
        string side;
        Game *game;
    public:
        virtual ~Player() = 0;
};


#endif

