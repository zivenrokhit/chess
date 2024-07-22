#include "tile.h"

// ctor initializes piece to mullptr
Tile::Tile() : piece(nullptr) {}

// dtor to clean dynamically allocated objects
Tile::~Tile() {
    delete piece; // if Piece is dynamically allocated
}

bool Tile::isEmpty() const {
    return piece == nullptr;
}

// remove piece from the tile
void Tile::killPiece() {
    delete piece; // delete Piece object if dynamically allocated
    piece = nullptr;
}


void Tile::setPosition(Piece* newPiece) {
    piece = newPiece; // assign new piece object override
}
