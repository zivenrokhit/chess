#include "piece.h"

Piece::Piece(Tile* position, bool hasMoved, const std::string& colour, const std::string& name)
    : position(position), hasMoved(hasMoved), colour(colour), name(name) {}
