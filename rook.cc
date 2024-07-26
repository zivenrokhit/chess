#include "rook.h"

Rook::Rook(int row, int col, Board *board ,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos ,bool hasMoved)
    : Piece(row, col,board , colour, "ROOK", vecEndPos), hasMoved(hasMoved) {}

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

   for (auto it = vecEndPos.begin(); it != vecEndPos.end(); it++){
        if (it->first < 0 || it->second > 7)
        {
            vecEndPos.erase(it);
        }
    }
    for (auto it = vecEndPos.begin(); it != vecEndPos.end(); it++){
            // Check if the pair should be removed
            if (this->board->board[it->first][it->second] != "_"){ // means its not empty so we need to check if its our piece or opp piece
                // check white pieces
                if(this->colour == "WHITE"){
                    for (auto itr : this->board->getWhitePieces())
                    {
                        pair<int, int> tempPair;
                        tempPair.first = it->first;
                        tempPair.second = it->second;
                        if (itr->getCurrPos() == tempPair)
                        {
                            vecEndPos.erase(it);
                        }
                    }              
                } else {
                    for (auto itr : this->board->getBlackPieces())
                    {
                        pair<int, int> tempPair;
                        tempPair.first = it->first;
                        tempPair.second = it->second;
                        if (itr->getCurrPos() == tempPair)
                        {
                            vecEndPos.erase(it);
                        }
                    }
                }
            } // end if
        }

    return vecEndPos;
}

bool Rook::canMove(const pair<int, int> endPos) const {
    for (const auto& pos : vecEndPos) {
        if (endPos == pos)
            return true;
    }
    return false;
}
