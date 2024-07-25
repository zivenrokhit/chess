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
    const vector<pair<int,int>> vecEndPos;
    public:
    Piece(int row, int col, Board *board,const string& colour, const char& symbol,const vector<pair<int,int>> vecEndPos);
    virtual bool isCaptured() const = 0;
    virtual void print() const = 0;
    virtual bool canMove(const pair<int,int> endPos) const = 0;
    vector<pair<int, int>> getCurrPos() const;
    string getColour() const;
    string getSymbol() const;
    vector<pair<int,int>> getMoves() const;
    virtual ~Piece() = default;
};

#endif // PIECE_H
