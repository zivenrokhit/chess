#include "king.h"
using namespace std;

King::King(int row, int col, Board *board ,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos ,bool hasMoved)
    : Piece(row, col,board , colour, "KING", vecEndPos), hasMoved(hasMoved){}

bool King::isCaptured() const
{
    return false;
}
vector<pair<int, int>> King::listOfEndPositions() {
    vector<pair<int, int>> vecEndPos;

    vecEndPos.emplace_back(this->row - 1, this->col);
    vecEndPos.emplace_back(this->row + 1, this->col);
    vecEndPos.emplace_back(this->row, this->col - 1);
    vecEndPos.emplace_back(this->row, this->col + 1);
    vecEndPos.emplace_back(this->row + 1, this->col + 1);
    vecEndPos.emplace_back(this->row - 1, this->col + 1);
    vecEndPos.emplace_back(this->row + 1, this->col - 1);
    vecEndPos.emplace_back(this->row - 1, this->col - 1);

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

bool King::canMove(const pair<int,int> endPos) const
{
    for (auto itm : vecEndPos)
    {
        if ( endPos.first== itm.first && endPos.second == itm.second)
        {
            return true;
            break;
        }
    }
    return false;
}
