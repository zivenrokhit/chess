#ifndef KING_H
#define KING_H

#include <vector>
#include <utility>
#include "piece.h"
#include <string>

using namespace std;

class King : public Piece {
    private:
    bool hasMoved;
    public:
    King(int row, int col, Board *board ,const string& colour, const char& symbol, bool hasMoved);

    bool isCaptured() const override;
    vector<pair<int,int>> listOfEndPositions() override;
    bool canMove(const pair<int,int> endPos,const vector<pair<int,int>> vecEndPos) const override;
   
};

#endif // KING_H
