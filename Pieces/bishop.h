#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(int row, int col, Board *board, const string& colour, const char& symbol);

    bool isCaptured() const override;
    vector<pair<int,int>> listOfEndPositions() override;
    bool canMove(const pair<int,int> endPos, const vector<pair<int,int>> vecEndPos) const override;
};

#endif // BISHOP_H
