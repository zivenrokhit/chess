#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
public:
    Pawn(Tile* position, bool hasMoved, const std::string& colour);

    bool isCaptured() const override;
    void print() const override;
    bool canMove(const std::string& start, const std::string& end) const override;
};

#endif // PAWN_H
