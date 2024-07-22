#include "bishop.h"

Bishop::Bishop(Tile* position, bool hasMoved, const std::string& colour)
    : Piece(position, hasMoved, colour, "Bishop") {}

bool Bishop::isCaptured() const {
    return false;
}

void Bishop::print() const {
    std::cout << "Bishop, Colour: " << colour << ", Position: " << position << ", Has moved: " << (hasMoved ? "Yes" : "No") << std::endl;
}

bool Bishop::canMove(const std::string& start, const std::string& end) const {
    //movement
    
    return false;
}
