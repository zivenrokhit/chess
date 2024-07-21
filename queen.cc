#include "queen.h"

Queen::Queen(Tile* position, bool hasMoved, const std::string& colour)
    : Piece(position, hasMoved, colour, "Queen") {}

bool Queen::isCaptured() const {
    return false;
}

void Queen::print() const {
    std::cout << "Queen, Colour: " << colour << ", Position: " << position << ", Has moved: " << (hasMoved ? "Yes" : "No") << std::endl;
}

bool Queen::canMove(const std::string& start, const std::string& end) const {
    //movement
    return false;
}
