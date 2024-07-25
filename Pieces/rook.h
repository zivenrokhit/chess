#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
public:
    Rook(int row, int col, Board *board, const string& colour, const char& symbol);

    bool isCaptured() const override;
    vector<pair<int,int>> listOfEndPositions() override;
    bool canMove(const pair<int,int> endPos, const vector<pair<int,int>> vecEndPos) const override;
};

#endif // ROOK_H
