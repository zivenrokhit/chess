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

void Piece::setMoves() {
    this->vecEndPos = this->getMoves();
}