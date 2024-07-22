#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Tile;

class Piece {
    Tile* position; 
    bool hasMoved;
    std::string colour;
    std::string name;

public:
    Piece(Tile* position, bool hasMoved, const std::string& colour, const std::string& name);

    virtual bool isCaptured() const = 0;

    virtual void print() const = 0;

    virtual bool canMove(const std::string& start, const std::string& end) const = 0;
    
};

#endif // PIECE_H
