#include "piece.h"

Piece::Piece(int row, int col, Board *board, const string& colour, const string& symbol, vector<pair<int, int>> vecEndPos)
    : row(row), col(col), board(board), colour(colour), symbol(symbol), vecEndPos(vecEndPos) {}

    
pair<int, int> Piece::getCurrPos() const{
    pair <int,int> pos(row,col);
    return pos;
}
string Piece::getColour() const{
    return colour;
}
string Piece::getSymbol() const{
    return this->symbol;
}
vector<pair<int,int>> Piece::getMoves() const {
    return vecEndPos;
}

void Piece::setCurrentPos(int row, int col) {
    this->row = row;
    this->col = col;
}

void Piece::filterForCauseCheck() {
    for (auto move : this->getMoves()) {
        // temporarily removed the piece;
        Piece *dyingPiece = this->board->getGame()->removePiece(move.first, move.second);
        this->board->getGame()->makeMove(dyingPiece->colour == "BLACK" ? true : false, 
                                           this->getCurrPos().first, this->getCurrPos().second,
                                           move.first, move.second );
        if (dyingPiece->colour == "WHITE") {
            if (this->board->isBlackChecked()) {
                this->board->getGame()->addPiece(false, dyingPiece->getSymbol(), dyingPiece->getCurrPos().first, dyingPiece->getCurrPos().second);
                for (auto itr = this->vecEndPos.begin(); itr != this->vecEndPos.end(); ++itr) {
                    if ((*itr) == move) this->vecEndPos.erase(itr);
                }
            }
        }
        if (dyingPiece->colour == "BLACK") {
            if (this->board->isWhiteChecked()) {
                this->board->getGame()->addPiece(true, dyingPiece->getSymbol(), dyingPiece->getCurrPos().first, dyingPiece->getCurrPos().second);
                for (auto itr = this->vecEndPos.begin(); itr != this->vecEndPos.end(); ++itr) {
                    if ((*itr) == move) this->vecEndPos.erase(itr);
                }
            }
        }
    }
}

void Piece::setMoves() {
    this->vecEndPos = this->getMoves();
}

