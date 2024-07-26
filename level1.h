#ifndef Level1_H
#define Level1_H
#include "computer.h"
#include "board.h"
#include <utility>
#include <cstdlib>
#include <string>

using namespace std;
class Level1: public Computer {
    public:
    Level1(Game *game);
    ~Level1()= default;
    pair<int,int> getRandomMove(const vector<pair<int,int>> vecEndPos);
    vector<pair<int,int>> Level1::getRandomPiece(bool isBlackTurn) // picks random piece, invokes getrandom move
};

#endif

