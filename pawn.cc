#include "pawn.h"

Pawn::Pawn(Tile* position, bool hasMoved, const std::string& colour)
    : Piece(position, hasMoved, colour, "Pawn") {}

bool Pawn::isCaptured() const {
    //stuffs
    return false;
}

void Pawn::print() const {
    std::cout << "Pawn, Colour: " << colour << ", Position: " << position << ", Has moved: " << (hasMoved ? "Yes" : "No") << std::endl;
}

bool Pawn::canMove(const std::string& start, const std::string& end) const {
    //movement
    return false;
}
