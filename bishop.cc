#include "bishop.h"

Bishop::Bishop(int row, int col, Board *board ,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos)
    : Piece(row, col,board , colour, "BISHOP",vecEndPos) {}

bool Bishop::isCaptured() const {
    return false;
}

vector<pair<int, int>> Bishop::listOfEndPositions() {
    vector<pair<int, int>> vecEndPos;

    // Bishop movements: diagonal movements
    for (int i = -7; i <= 7; ++i) {
        if (i != 0) {
            if (row + i >= 0 && row + i < 8 && col + i >= 0 && col + i < 8) vecEndPos.emplace_back(row + i, col + i); // bottom-right and top-left
            if (row + i >= 0 && row + i < 8 && col - i >= 0 && col - i < 8) vecEndPos.emplace_back(row + i, col - i); // bottom-left and top-right
        }
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

bool Bishop::canMove(const pair<int, int> endPos) const {
    for (const auto& pos : vecEndPos) {
        if (endPos == pos)
            return true;
    }
    return false;
}
