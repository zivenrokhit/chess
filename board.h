#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "observer.h"
#include "subject.h"
#include "piece.h"
#include "game.h"
#include <map>
#include <string>

// concrete subject
class Board: public Subject {
    // vector<Observer *>observers; already part of the subject class
    friend class Game;
    vector<Piece *>whitePieces;
    vector<Piece *>blackPieces;
    Game *game;
    public:
        string board[8][8];
        Board(string board[8][8], Game *game);
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
        bool isSquareChecked(int row, int col);
        Game *getGame();
        vector<Piece *> getBlackPieces();
        vector<Piece *> getWhitePieces();
        ~Board();
};



#endif
