#include "knight.h"

Knight::Knight(string currPos, bool hasMoved, const string& colour)
    : Piece(currPos, hasMoved, colour, "Knight") {}

bool Knight::isCaptured() const {
    return false;
}

void Knight::print() const {
    // name N and n
}

bool Knight::canMove(const std::string& start, const std::string& end) const {
    //movement
    return false;
}
