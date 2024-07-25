#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"


class Knight : public Piece {
public:

    Knight(int row, int col, Board *board,const string& colour, const char& symbol,const vector<pair<int,int>> vecEndPos);
    bool isCaptured() const override;
    vector<pair<int,int>> listOfEndPositions() override;
    bool canMove(const pair<int,int> endPos) const override;
};

#endif // KNIGHT_H
