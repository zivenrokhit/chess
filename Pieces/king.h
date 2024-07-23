#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
public:
    King(string currPos, bool hasMoved, const string& colour);

    bool isCaptured() const override;
    void print() const override;
    bool canMove(const string& start, const string& end) const override;
};

#endif // KING_H
