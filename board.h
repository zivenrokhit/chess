#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include <string>
#include "observer.h"
#include "subject.h"
#include "piece.h"
#include "game.h"

using namespace std;
class Game;
// concrete subject
class Board: public Subject {
    // vector<Observer *>observers; already part of the subject class
    friend class Game;
    vector<Piece *> whitePieces;
    vector<Piece *> blackPieces;
    Game *game;
public:
    string **board;
    Board(Game *game);
    void printBoard(); // done
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
