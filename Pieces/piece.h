#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Piece {
    protected:
    int row;
    int col;
    string colour;
    char symbol;
    Board *board;
    

    public:
    Piece(int row, int col, Board *board,const string& colour, const char& symbol);

    virtual bool isCaptured() const = 0;

    virtual void print() const = 0;

    virtual bool canMove(const string& start, const string& end) const = 0;
    virtual vector<pair<int, int>>  getCurrPos() const = 0;
    virtual string getColour() const = 0;
    
};

#endif // PIECE_H
