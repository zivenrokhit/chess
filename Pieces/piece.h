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

    bool isCaptured() const;

    void print() const;

    bool canMove(const std::string& start, const std::string& end) const;
    
};

#endif // PIECE_H
