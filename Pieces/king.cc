#include "king.h"
#include <vector>
#include <utility>
#include <string>

using namespace std;

King::King(int row, int col, bool hasMoved, const string &colour, string name)
    : Piece(row, col, hasMoved, colour, "KING") {}

bool King::isCaptured() const
{
    return false;
}
vector<pair<int, int>> King::listOfEndPositions(Board &board)
{
    // weed out positions that are filled with own color piece, off the board DONE, check for check
    // regualr move sideways, forwards, backwards, diagonal
    vector<String> vecEndPos;
    // king can move in all direction but one square at a time, come up with all possible moves
    pair<int, int> coordinates(this->row - 1, this->col);
    vecEndPos.emplace_back(coordinates); // left 1
    pair<int, int> coordinates(this->row + 1, this->col);
    vecEndPos.emplace_back(coordinates); // right 1
    pair<int, int> coordinates(this->row, this->col - 1);
    vecEndPos.emplace_back(coordinates); // down 1
    pair<int, int> coordinates(this->row, this->col + 1);
    vecEndPos.emplace_back(coordinates); // up 1
    pair<int, int> coordinates(this->row + 1, this->col + 1);
    vecEndPos.emplace_back(coordinates); // up right 1
    pair<int, int> coordinates(this->row - 1, this->col + 1);
    vecEndPos.emplace_back(coordinates); // up left 1
    pair<int, int> coordinates(this->row + 1, this->col - 1);
    vecEndPos.emplace_back(coordinates); // down right 1
    pair<int, int> coordinates(this->row - 1, this->col - 1);
    vecEndPos.emplace_back(coordinates); // down left 1

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
            if(this->colour == "WHITE"){
                for (itr : this->board->getWhitePieces())
                {
                    pair<int, int> tempPair;
                    tempPair.first = it.first;
                    tempPair.second = it.second;
                    if (itr.getCurrPos() == tempPair)
                    {
                        vecEndPos.erase(it);
                    }
                }              
            } else {
                for (itr : this->board->getBlackPieces())
                {
                    pair<int, int> tempPair;
                    tempPair.first = it.first;
                    tempPair.second = it.second;
                    if (itr.getCurrPos() == tempPair)
                    {
                        vecEndPos.erase(it);
                    }
                }
            }
        } // end if
    }

    // check for check NOT IMPLEMENTED
    // CASTLING NOT IMPLEMENTED
    // HOPE just basic moves around the board are in vec and moves that result in taking our own piece are removed
    return vecEndPos
}

bool King::canMove(const string &end, vector<String> vecEndPos) const
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
