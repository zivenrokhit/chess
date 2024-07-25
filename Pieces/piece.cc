#include "piece.h"

Piece::Piece(int row, int col, Board *board,const string& colour, const char& symbol)
    :  row(row), col(col), board(board), colour(colour), symbol(symbol) {}
vector<pair<int, int>> Piece::getCurrPos() const{
    pair <int,int> pos(row,col);
    return pos;
}
string Piece::getColour() const{
    return colour;
}
string Piece::getSymbol() const{
    return symbol;
}
vector<pair<int,int>> Piece::getMoves() const {
    return vecEndPos;
}
