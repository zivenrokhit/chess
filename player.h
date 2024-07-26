#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Game;

class Player {
    friend class Game;
protected:
    string side;
    Game *game;
public:
    virtual ~Player() = 0;
};

#endif
