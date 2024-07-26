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
    string board[8][8];
    vector<Piece *>whitePieces;
    vector<Piece *>blackPieces;
    bool resigned;
    Game *game;
    public:
        Board(string board[8][8], Game *game);
        void printBoard(); // done
        bool isWhiteChecked();
        bool isBlackChecked();
        bool isSquareChecked(bool isBlackTurn, int row, int col);
        bool wouldCauseCheck(int startRow, int startCol, int endRow, int endCol);
        Piece *getWhiteKing();
        Piece *getBlackKing();
        bool kingsOnly();
        bool isCheckmate(bool isBlackTurn);
        bool isStalemate(bool isBlackTurn);
        bool isCheck(bool); 
        bool isSquareChecked(int row, int col);
        Game *getGame();
        ~Board();
};



#endif
