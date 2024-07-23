#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Piece {
    string currPos;
    bool hasMoved;
    string colour;
    char symbol;

public:
    Piece(string currPos, bool hasMoved, const string& colour, const char& symbol);

    virtual bool isCaptured() const = 0;

    virtual void print() const = 0;

    virtual bool canMove(const string& start, const string& end) const = 0;
    
};

#endif // PIECE_H
