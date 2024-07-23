#include "king.h"

King::King(string currPos, bool hasMoved, const string& colour)
    : Piece(currPos, hasMoved, colour, "King") {}

bool King::isCaptured() const {
    return false;
}

void King::print() const {
    // print depending on color
}

bool King::canMove(const string& start, const string& end) const {
    //impl movement
    return false;
}
