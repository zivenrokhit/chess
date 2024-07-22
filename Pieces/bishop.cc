#include "bishop.h"
#include <iostream>
#include <cmath>

#include "board.h" // for isCaptured

Bishop::Bishop(Tile* position, bool hasMoved, const std::string& colour)
    : Piece(position, hasMoved, colour, "Bishop") {}

bool Bishop::isCaptured() const {

    // hypothetical:
    // Check if the bishop is still on the board
    return !Board::instance().isPieceOnBoard(this);
}

void Bishop::print() const {
    std::cout << "Bishop, Colour: " << colour
              << ", Position: " << position
              << ", Has moved: " << (hasMoved ? "Yes" : "No") << std::endl;
}

bool Bishop::canMove(const std::string& start, const std::string& end) const {
    auto [startX, startY] = positionToCoordinates(start);
    auto [endX, endY] = positionToCoordinates(end);

    // check if the move is diagonal
    if (std::abs(startX - endX) == std::abs(startY - endY)) {
        // movement is diagonal; check for obstacles if needed
        // placeholder: Actual obstacle detection code would be here
        return true;
    }

    return false;
}

// helper function to convert position to coordinates
std::pair<int, int> Bishop::positionToCoordinates(const std::string& position) const {
    char file = position[0];
    char rank = position[1];

    // convert file (A-H) to 0-7 and rank (1-8) to 0-7
    int x = file - 'A';
    int y = rank - '1';

    return {x, y};
}
