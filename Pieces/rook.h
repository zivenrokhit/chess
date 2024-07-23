#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
public:
    Rook(string currPos, bool hasMoved, const std::string& colour);

    bool isCaptured() const override;
    void print() const override;
    bool canMove(const std::string& start, const std::string& end) const override;
};

#endif // ROOK_H
