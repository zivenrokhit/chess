#include "pawn.h"

Pawn::Pawn(int row, int col, Board *board ,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos)
    : Piece(row, col,board , colour, "PAWN",vecEndPos) {}

bool Pawn::isCaptured() const {
    return false;
}
vector<pair<int, int>> Pawn::listOfEndPositions() {
    vector<pair<int, int>> vecEndPos;

    if (this->row == 1) {
        pair<int, int> coordinates(this->row + 1, this->col);
        vecEndPos.emplace_back(coordinates); // move up 1
        coordinates = pair<int, int>(this->row + 2, this->col);
        vecEndPos.emplace_back(coordinates); // move up 2
        coordinates = pair<int, int>(this->row + 1, this->col + 1);
        vecEndPos.emplace_back(coordinates); // move up 1 right 1
        coordinates = pair<int, int>(this->row + 1, this->col - 1);
        vecEndPos.emplace_back(coordinates); // move up 1 left 1
    } else {
        pair<int, int> coordinates(this->row + 1, this->col);
        vecEndPos.emplace_back(coordinates); // move up 1
        coordinates = pair<int, int>(this->row + 1, this->col + 1);
        vecEndPos.emplace_back(coordinates); // move up 1 right 1
        coordinates = pair<int, int>(this->row + 1, this->col - 1);
        vecEndPos.emplace_back(coordinates); // move up 1 left 1
    }

    for (auto it = vecEndPos.begin(); it != vecEndPos.end();) {
        if (it->first < 0 || it->first > 7 || it->second < 0 || it->second > 7) {
            it = vecEndPos.erase(it);
        } else {
            ++it;
        }
    }

    for (auto it = vecEndPos.begin(); it != vecEndPos.end();) {
        if (this->board->board[it->first][it->second] != "_") {
            bool isOwnPiece = false;
            if (this->colour == "WHITE") {
                for (auto itr : this->board->getWhitePieces()) {
                    if (itr->getCurrPos() == *it) {
                        isOwnPiece = true;
                        break;
                    }
                }
            } else {
                for (auto itr : this->board->getBlackPieces()) {
                    if (itr->getCurrPos() == *it) {
                        isOwnPiece = true;
                        break;
                    }
                }
            }
            if (isOwnPiece) {
                it = vecEndPos.erase(it);
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }

    return vecEndPos;
}


bool Pawn::canMove(const pair<int,int> endPos) const {
    for (auto itm : vecEndPos)
    {
        if (endPos.first == itm.first && endPos.second == itm.second)
        {
            return true;
            break;
        }
    }
    return false;
}



