#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
public:
    King(Tile* position, bool hasMoved, const std::string& colour);

    bool isCaptured() const override;
    void print() const override;
    bool canMove(const std::string& start, const std::string& end) const override;
};

#endif // KING_H
