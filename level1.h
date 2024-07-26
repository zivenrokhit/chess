#ifndef LEVEL1_H
#define LEVEL1_H

#include "computer.h"
#include "board.h"
#include <utility>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Game;

class Level1 : public Computer {
    Game *game;
public:
    Level1(Game *game);
    ~Level1() = default;
    pair<int, int> getRandomMove(const vector<pair<int, int>> vecEndPos);
    vector<pair<int, int>> getRandomPiece(bool isBlackTurn);
};

#endif
