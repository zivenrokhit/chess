#include "knight.h"

#include <vector>
#include <utility>
#include <string>

Knight::Knight(int row, int col, Board *board ,const string& colour, const string& symbol,const vector<pair<int,int>> vecEndPos)
    : Piece(row, col,board , colour, "KNIGHT",vecEndPos) {}

bool Knight::isCaptured() const {
    return false;
}


vector<pair<int, int>> Knight::listOfEndPositions()
{
    // weed out positions that are filled with own color piece, off the board 
    // regular move L shape
    vector<pair<int, int>> vecEndPos;
    pair<int, int> coordinates(this->row - 1, this->col + 2);
    vecEndPos.emplace_back(coordinates); // up 2 left 1
    pair<int, int> coordinates2(this->row + 1, this->col + 2);
    vecEndPos.emplace_back(coordinates2); // up 2 right 1
    pair<int, int> coordinates3(this->row + 1, this->col - 2);
    vecEndPos.emplace_back(coordinates3); // down 2 right 1
    pair<int, int> coordinates4(this->row - 1, this->col - 2);
    vecEndPos.emplace_back(coordinates4); // down 2 left 1
    pair<int, int> coordinates5(this->row + 2, this->col + 1);
    vecEndPos.emplace_back(coordinates5); // up 1 right 2
    pair<int, int> coordinates6(this->row - 2, this->col + 1);
    vecEndPos.emplace_back(coordinates6); // up 1 left 2
    pair<int, int> coordinates7(this->row + 2, this->col - 1);
    vecEndPos.emplace_back(coordinates7); // down 1 right 2
    pair<int, int> coordinates8(this->row - 2, this->col - 1);
    vecEndPos.emplace_back(coordinates8); // down 1 left 2
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
    // HOPE just basic moves around the board are in vec and moves that result in taking our own piece are removed
    return vecEndPos;
}

bool Knight::canMove(const pair<int,int> endPos) const {
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
