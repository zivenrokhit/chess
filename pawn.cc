#include "pawn.h"

Pawn::Pawn(int row, int col, Board *board ,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos)
    : Piece(row, col,board , colour, "PAWN",vecEndPos) {}

bool Pawn::isCaptured() const {
    return false;
}
vector<pair<int, int>> Pawn::listOfEndPositions()
{
    // pawns should be able to move forward 1/2, diagonal 1 left or right
    // mov forward 2 only allowed when pawn on first row

    if(this->row == 1){
        vector<pair<int, int>> vecEndPos;
        pair<int, int> coordinates(this->row, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1
        pair<int, int> coordinates(this->row, this->col + 2); 
        vecEndPos.emplace_back(coordinates); // up 2
        pair<int, int> coordinates(this->row  + 1, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1 right 1
        pair<int, int> coordinates(this->row  - 1, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1 left 1
    } else {
        vector<string> vecEndPos;
        pair<int, int> coordinates(this->row, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1
        pair<int, int> coordinates(this->row  + 1, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1 right 1
        pair<int, int> coordinates(this->row  - 1, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1 left 1
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



