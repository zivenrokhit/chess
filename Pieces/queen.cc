#include "queen.h"

Queen::Queen(int row, int col, Board *board ,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos)
: Piece(row, col,board , colour, "QUEEN",vecEndPos) {}

bool Queen::isCaptured() const {
    return false;
}

vector<pair<int, int>> Queen::listOfEndPositions() {
    vector<pair<int, int>> vecEndPos;

    // Queen's movements: Rook + Bishop
    // horizontal, vertical, and diagonal movements

    // horizontal and vertical moves
    for (int i = 0; i < 8; ++i) {
        if (i != row) vecEndPos.emplace_back(i, col); // vertical
        if (i != col) vecEndPos.emplace_back(row, i); // horizontal
    }

    // diagonal moves
    for (int i = -7; i <= 7; ++i) {
        if (i != 0) {
            if (row + i >= 0 && row + i < 8 && col + i >= 0 && col + i < 8) vecEndPos.emplace_back(row + i, col + i); // bottom-right and top-left
            if (row + i >= 0 && row + i < 8 && col - i >= 0 && col - i < 8) vecEndPos.emplace_back(row + i, col - i); // bottom-left and top-right
        }
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

bool Queen::canMove(const pair<int, int> endPos) const {
    for (const auto& pos : vecEndPos) {
        if (endPos == pos)
            return true;
    }
    return false;
}
