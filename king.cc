#include "king.h"

King::King(Tile* position, bool hasMoved, const std::string& colour)
    : Piece(position, hasMoved, colour, "King") {}

bool King::isCaptured() const {
    return false;
}

void King::print() const {
    std::cout << "King, Colour: " << colour << ", Position: " << position << ", Has moved: " << (hasMoved ? "Yes" : "No") << std::endl;
}

bool King::canMove(const std::string& start, const std::string& end) const {
    //impl movement
    return false;
}
