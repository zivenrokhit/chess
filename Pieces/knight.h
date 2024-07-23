#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
public:
    Knight(string currPos, bool hasMoved, const string& colour);

    bool isCaptured() const override;
    void print() const override;
    bool canMove(const string& start, const string& end) const override;
};

#endif // KNIGHT_H
