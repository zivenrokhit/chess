#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>
#include "observer.h"
#include "subject.h"
#include "piece.h"
#include <map>

// concrete subject
class Board: public Subject {
    // vector<Observer *>observers; already part of the subject class
    string board[8][8];
    vector<Piece *>whitePieces;
    vector<Piece *>blackPieces;
    bool resigned;
    public:
        Board(string board[8][8]);
        void printBoard(); // done
        bool kingsOnly();
        bool isCheckmate();
        bool isStalemate();
        bool isCheck(bool); 
        bool isSquareChecked(int row, int col);
        ~Board();
};



#endif
