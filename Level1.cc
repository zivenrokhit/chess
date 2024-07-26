#include "level1.h"


Level1::Level1(Game *game) : game(game) {}




vector<pair<int,int>> Level1::getRandomPiece(bool isBlackTurn){
    vector<pair<int,int>> coordinates;
    pair<int,int> starting;
    pair<int,int> ending;

    if(isBlackTurn){
        // select from black pieces
        int numOfBlackPieces = this->game->blackPieces.size();
        int index = rand() % numOfBlackPieces;
        starting.first = this->game->blackPieces[index]->getCurrPos().first;
        starting.second = this->game->blackPieces[index]->getCurrPos().second;
        coordinates.emplace_back(starting);
        ending.first = (this->getRandomMove(this->game->blackPieces[index]->getMoves())).first;
        ending.second = (this->getRandomMove(this->game->blackPieces[index]->getMoves())).second;
        coordinates.emplace_back(ending);
        return coordinates;
    } else { 
        int numOfWhitePieces = this->game->whitePieces.size();
        int index = rand() % numOfWhitePieces;
        starting.first = this->game->whitePieces[index]->getCurrPos().first;
        starting.second = this->game->whitePieces[index]->getCurrPos().second;
        coordinates.emplace_back(starting);
        ending.first = (this->getRandomMove(this->game->whitePieces[index]->getMoves())).first;
        ending.second = (this->getRandomMove(this->game->whitePieces[index]->getMoves())).second;
        coordinates.emplace_back(ending);
        return coordinates;
     
    }
    
}

pair<int,int> Level1::getRandomMove(const vector<pair<int,int>> vecEndPos){
    if(vecEndPos.size() > 0){
        int index = rand() % vecEndPos.size();
        return vecEndPos[index];
    } else {
        this->getRandomPiece(this->side == "BLACK");
    }
}



