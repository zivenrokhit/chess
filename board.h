#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include "observer.h"
#include "subject.h"
#include "piece.h"
#include "game.h"
#include <string>

using namespace std;
class Game;
class Board: public Subject {
    friend class Game;
    vector<Piece *> whitePieces;
    vector<Piece *> blackPieces;
    Game *game;
public:
    string **board;
    Board(Game *game);
    void printBoard();
    bool isWhiteChecked();
    bool isBlackChecked();
    bool isSquareChecked(bool isBlackTurn, int row, int col);
    Piece *getWhiteKing();
    Piece *getBlackKing();
    bool kingsOnly();
    bool isCheckmate(bool isBlackTurn);
    bool isStalemate(bool isBlackTurn);
    bool isCheck(bool isBlackTurn); 
    Game *getGame();
    vector<Piece *> getBlackPieces();
    vector<Piece *> getWhitePieces();
    ~Board();
};

#endif
