#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
public:
    Pawn(string currPos, bool hasMoved, const string& colour);

    bool isCaptured() const override;
    void print() const override;
    bool canMove(const string& start, const string& end) const override;
};

#endif // PAWN_H
