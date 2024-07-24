#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
public:
    Knight(int row, int col,const string& colour, string name);
    bool isCaptured() const override;
    vector<pair<int,int>> listOfEndPositions() override;
    bool canMove(const string& end,vector<String> vecEndPos) const override;
};

#endif // KNIGHT_H
