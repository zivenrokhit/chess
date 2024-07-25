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
        vector<String> vecEndPos;
        pair<int, int> coordinates(this->row, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1
        pair<int, int> coordinates(this->row, this->col + 2); 
        vecEndPos.emplace_back(coordinates); // up 2
        pair<int, int> coordinates(this->row  + 1, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1 right 1
        pair<int, int> coordinates(this->row  - 1, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1 left 1
    } else {
        vector<String> vecEndPos;
        pair<int, int> coordinates(this->row, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1
        pair<int, int> coordinates(this->row  + 1, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1 right 1
        pair<int, int> coordinates(this->row  - 1, this->col + 1); 
        vecEndPos.emplace_back(coordinates); // up 1 left 1
    }

    // if piece is blocking forward movement remove it, any piece
    for (auto it = vecEndPos.begin(); it != vecEndPos.end(); it++){
        if( board[it.first][it.second]!= "_" ||  board[it.first][it.second]!= "_" ){
            // check whats in it
            if(this->colour == "WHITE"){
                for (itr : this->board->getWhitePieces()){
                    pair<int, int> tempPair;
                    tempPair.first = it.first;
                    tempPair.second = it.second;
                    if (itr.getCurrPos() == tempPair)
                    {
                        vecEndPos.erase(it); // if a white piece is infront or diagonal we remove it
                    }
                }

            } else {
                for (itr : this->board->getBlackPieces()){
                    pair<int, int> tempPair;
                    tempPair.first = it.first;
                    tempPair.second = it.second;
                    if (itr.getCurrPos() == tempPair)
                    {
                        vecEndPos.erase(it); // if a Black piece is infront or diagonal we remove it
                    }
                }  
            }
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



