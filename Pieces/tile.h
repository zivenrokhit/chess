#ifndef TILE_H
#define TILE_H

#include "piece.h" 

class Tile {
private:
    Piece* piece; 
public:
    Tile();
    ~Tile();

    bool isEmpty() const;

    void killPiece(); // remove piece from tile

    void setPosition(Piece* piece); // set piece at this position
};

#endif // TILE_H
