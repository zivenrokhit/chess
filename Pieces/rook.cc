#include "rook.h"

Rook::Rook(int row, int col, Board *board, const string& colour, const char& symbol)
    : Piece(row, col, board, colour, symbol) {}

bool Rook::isCaptured() const {
    return false;
}

vector<pair<int, int>> Rook::listOfEndPositions() {
    vector<pair<int, int>> vecEndPos;

    // Rook's movements: horizontal + vertical
    for (int i = 0; i < 8; ++i) {
        if (i != row) vecEndPos.emplace_back(i, col); // vertical
        if (i != col) vecEndPos.emplace_back(row, i); // horizontal
    }

    // filter out positions off board or occupied by own pieces
    vecEndPos.erase(remove_if(vecEndPos.begin(), vecEndPos.end(),
        [this](const pair<int, int>& pos) {
            if (pos.first < 0 || pos.first >= 8 || pos.second < 0 || pos.second >= 8)
                return true;
            if (board->getPieceAt(pos.first, pos.second) != nullptr &&
                board->getPieceAt(pos.first, pos.second)->getColour() == this->colour)
                return true;
            return false;
        }), vecEndPos.end());

    return vecEndPos;
}

bool Rook::canMove(const pair<int, int> endPos, const vector<pair<int, int>> vecEndPos) const {
    for (const auto& pos : vecEndPos) {
        if (endPos == pos)
            return true;
    }
    return false;
}
