#include "knight.h"

Knight::Knight(Tile* position, bool hasMoved, const std::string& colour)
    : Piece(position, hasMoved, colour, "Knight") {}

bool Knight::isCaptured() const {
    return false;
}

void Knight::print() const {
    std::cout << "Knight, Colour: " << colour << ", Position: " << position << ", Has moved: " << (hasMoved ? "Yes" : "No") << std::endl;
}

bool Knight::canMove(const std::string& start, const std::string& end) const {
    //movement
    return false;
}
