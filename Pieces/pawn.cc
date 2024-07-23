#include "pawn.h"

Pawn::Pawn(string currPos, bool hasMoved, const std::string& colour)
    : Piece(position, hasMoved, colour, "Pawn") {}

bool Pawn::isCaptured() const {
    //stuffs
    return false;
}

void Pawn::print() const {
    // name depending on color
}

bool Pawn::canMove(const string& start, const string& end) const {
    //movement
    return false;
}
