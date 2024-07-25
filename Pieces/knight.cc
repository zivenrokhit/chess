#include "knight.h"

#include <vector>
#include <utility>
#include <string>

Knight::Knight(int row, int col, Board *board ,const string &colour, const char& symbol,const vector<pair<int,int>> vecEndPos)
    : Piece(row, col,board , colour, "KNIGHT",vecEndPos) {}

bool Knight::isCaptured() const {
    return false;
}


vector<pair<int, int>> Knight::listOfEndPositions()
{
    // weed out positions that are filled with own color piece, off the board 
    // regular move L shape
    vector<String> vecEndPos;
    pair<int, int> coordinates(this->row - 1, this->col + 2);
    vecEndPos.emplace_back(coordinates); // up 2 left 1
    pair<int, int> coordinates(this->row + 1, this->col + 2);
    vecEndPos.emplace_back(coordinates); // up 2 right 1
    pair<int, int> coordinates(this->row + 1, this->col - 2);
    vecEndPos.emplace_back(coordinates); // down 2 right 1
    pair<int, int> coordinates(this->row - 1, this->col -2);
    vecEndPos.emplace_back(coordinates); // down 2 left 1
    pair<int, int> coordinates(this->row + 2, this->col + 1);
    vecEndPos.emplace_back(coordinates); // up 1 right 2
    pair<int, int> coordinates(this->row - 2, this->col + 1);
    vecEndPos.emplace_back(coordinates); // up 1 left 2
    pair<int, int> coordinates(this->row + 2, this->col - 1);
    vecEndPos.emplace_back(coordinates); // down 1 right 2
    pair<int, int> coordinates(this->row - 2, this->col - 1);
    vecEndPos.emplace_back(coordinates); // down 1 left 2

    // first step remove all value that have row < 0 or col > 7
    // Iterate from the end of the vector to the beginning
    for (auto it = vecEndPos.begin(); it != vecEndPos.end(); it++){
        // Check if the pair should be removed
        if (it->first < 0 || it->second > 7)
        {
            vecEndPos.erase(it);
        }
    }
    // remove positions that are filled with my own piece
    for (auto it = vecEndPos.begin(); it != vecEndPos.end(); it++){
        // Check if the pair should be removed
        if (board[it->first][it->second] != "_"){ // means its not empty so we need to check if its our piece or opp piece
            // check white pieces
            if(this->colour == "WHITE"){ // what colo are we
                for (itr : this->board->getWhitePieces())
                {
                    pair<int, int> tempPair;
                    tempPair.first = row;
                    tempPair.second = col;
                    if (itr.getCurrPos() == tempPair)
                    {
                        vecEndPos.erase(it);
                        
                    }
                }              
            } else {
                for (itr : this->board->getBlackPieces())
                {
                    pair<int, int> tempPair;
                    tempPair.first = row;
                    tempPair.second = col;
                    if (itr.getCurrPos() == tempPair)
                    {
                        vecEndPos.erase(it);
                    }
                }
            }

        
        }
    }


    // HOPE just basic moves around the board are in vec and moves that result in taking our own piece are removed
    return vecEndPos
}

bool Knight::canMove(const pair<int,int> endPos, const vector<pair<int,int>> vecEndPos) const {
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
<<<<<<< HEAD






bool King::canMove(const string &end) const
{
    for (auto itm : vecEndPos)
    {
        if (end == itm)
        {
            return true;
            break;
        }
    }
    return false;
}
=======
>>>>>>> c6f71c465b8ee11e01625d2d3a3c2fa398b5316c
