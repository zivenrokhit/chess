#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
    
    public:
    Pawn(int row, int col, const string& colour, string& name);
    bool isCaptured() const override;
    vector<pair<int,int>> listOfEndPositions() override;
    bool canMove(const string& end,vector<String> vecEndPos) const override;
};

#endif // PAWN_H
