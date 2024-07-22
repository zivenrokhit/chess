#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(Tile* position, bool hasMoved, const std::string& colour);

    bool isCaptured() const override;
    void print() const override;
    bool canMove(const std::string& start, const std::string& end) const override;
};

#endif // BISHOP_H
