#ifndef KING_H
#define KING_H

#include <vector>
#include <utility>
#include "piece.h"
#include <string>

using namespace std;

class King : public Piece {

    public:
    King(int row, int col, bool hasMoved, const string& colour, string name);
    bool isCaptured() const override;
    vector<pair<int,int>> listOfEndPositions() override;
    bool canMove(const string& end,vector<String> vecEndPos) const override;
   
};

#endif // KING_H
