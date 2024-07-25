#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
public:
    Queen(int row, int col, Board *board,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos);

    bool isCaptured() const override;
    vector<pair<int,int>> listOfEndPositions() override;
    bool canMove(const pair<int,int> endPos) const override;
};

#endif // QUEEN_H
