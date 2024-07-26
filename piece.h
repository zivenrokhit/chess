#ifndef PIECE_H
#define PIECE_H


#include "board.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

class Board;


class Piece {
    protected:
    int row;
    int col;
    Board *board;
    string colour;
    string symbol;
    vector<pair<int,int>> vecEndPos;
    public:
    Piece(int row, int col, Board *board,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos);
    virtual bool isCaptured() const = 0;
    virtual bool canMove(const pair<int,int> endPos) const = 0;
    virtual vector<pair<int,int>> listOfEndPositions() = 0;
    pair<int, int> getCurrPos() const;
    string getColour() const;
    string getSymbol() const;
    vector<pair<int,int>> getMoves() const;
    virtual ~Piece() = default;
    void setCurrentPos(int row, int col);
    void setMoves();
    void filterForCauseCheck();
};

#endif // PIECE_H
