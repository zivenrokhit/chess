#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <vector>
#include <utility>
#include <string>
using namespace std;

class Pawn : public Piece {
    
    public:
    Pawn(int row, int col, Board *board,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos);
    bool isCaptured() const override;
    vector<pair<int,int>> listOfEndPositions() override;
    bool canMove(const pair<int,int> endPos) const override;
};

#endif // PAWN_H
