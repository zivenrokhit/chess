#include "bishop.h"

Bishop::Bishop(int row, int col, Board *board ,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos)
    : Piece(row, col,board , colour, "BISHOP", vecEndPos) {}

bool Bishop::isCaptured() const {
    return false;
}

vector<pair<int, int>> Bishop::listOfEndPositions() {
    vector<pair<int, int>> vecEndPos;

    // Bishop movements: diagonal movements
    for (int i = 1; i < 8; ++i) { // start from 1 to avoid no movement
        if (row + i < 8 && col + i < 8) vecEndPos.emplace_back(row + i, col + i); // bottom-right
        if (row + i < 8 && col - i >= 0) vecEndPos.emplace_back(row + i, col - i); // bottom-left
        if (row - i >= 0 && col + i < 8) vecEndPos.emplace_back(row - i, col + i); // top-right
        if (row - i >= 0 && col - i >= 0) vecEndPos.emplace_back(row - i, col - i); // top-left
    }

    // filter out positions off board or occupied by own pieces
    vecEndPos.erase(remove_if(vecEndPos.begin(), vecEndPos.end(),
        [this](const pair<int, int>& pos) {
            if (pos.first < 0 || pos.first > 7 || pos.second < 0 || pos.second > 7)
                return true;
            if (board->getPieceAt(pos.first, pos.second) != nullptr &&
                board->getPieceAt(pos.first, pos.second)->getColour() == this->colour)
                return true;
            return false;
        }), vecEndPos.end());

    return vecEndPos;
}

bool Bishop::canMove(const pair<int, int> endPos, const vector<pair<int, int>> vecEndPos) const {
    for (const auto& pos : vecEndPos) {
        if (endPos == pos)
            return true;
    }
    return false;
}
