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
        bool isValidMove(bool isBlackTurn, string startPos, string endPos); 
        // {
        // return piece.canMove;
        // also need to check who youre killing
        //     if (this->isBlackTurn) {
        //         for (itr : this->blackPieces) {
        //             if (itr.currentPos == startPos) {
        //                 if (itr.canMove(string endPos)) {
        //                     return True;
        //                 } else {
        //                     return False;
        //                 }
        //             }
        //         }
        //     }
        // }
        void makeMove(bool isBlackTurn, string startPos, string endPos);
        // // {
        // // 
        // row = endPos[0];
        //  col = endPos[1]
        // if (isBlackTurn) {
        //     for (itr : this->whitePieces) {
        //     // find piece that is getting killed and delete memory then remove from array
        //     if (itr.currentPos == endPos) {
        //         delete itr;
        //         this->whitePieces.erase(itr);
        //     }
        //     }
        // }
        //  this->board[row][col] = piece->symbol;
        // this->board[extract startPos] = '_';
        // piece->currentPosition = endPos;
        // }
        void printBoard(); // {this->notifyObservers()}
        bool kingsOnly();
        bool isCheckmate();
        bool isStalemate();
        bool isCheck();
        ~Board();
};



#endif
