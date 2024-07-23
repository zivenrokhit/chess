#include "rook.h"

Rook::Rook(string currPos, bool hasMoved, const std::string& colour)
    : Piece(Pos, hasMoved, colour, "Rook") {}

bool Rook::isCaptured() const {
    return false;
}

void Rook::print() const {
   // print stuffs
}

bool Rook::canMove(const std::string& start, const std::string& end) const {
    // movement
    return false;
}
