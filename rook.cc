#include "rook.h"

Rook::Rook(Tile* position, bool hasMoved, const std::string& colour)
    : Piece(position, hasMoved, colour, "Rook") {}

bool Rook::isCaptured() const {
    return false;
}

void Rook::print() const {
    std::cout << "Rook, Colour: " << colour << ", Position: " << position << ", Has moved: " << (hasMoved ? "Yes" : "No") << std::endl;
}

bool Rook::canMove(const std::string& start, const std::string& end) const {
    // movement
    return false;
}
