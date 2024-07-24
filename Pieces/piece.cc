#include "piece.h"

Piece::Piece(int row, int col, Board *board,const string& colour, const char& symbol)
    :  row(row), col(col), board(board), colour(colour), symbol(symbol) {}
