#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

class Piece {
    protected:
    int row;
    int col;
    Board *board;
    string colour;
    char symbol;
    public:
    Piece(int row, int col, Board *board,const string& colour, const char& symbol);
    virtual bool isCaptured() const = 0;
    virtual void print() const = 0;
    virtual bool canMove(const pair<int,int> endPos, const vector<pair<int,int>> vecEndPos) const = 0;
    vector<pair<int, int>> getCurrPos() const;
    string getColour() const;
    string getSymbol() const;
    virtual ~Piece() = default;
};

#endif // PIECE_H
