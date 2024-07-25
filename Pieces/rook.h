#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
    private:
        bool hasMoved;
    public:
        Rook(int row, int col, Board *board ,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos ,bool hasMoved);

        bool isCaptured() const override;
        vector<pair<int,int>> listOfEndPositions() override;
        bool canMove(const pair<int,int> endPos) const override;
};

#endif // ROOK_H
