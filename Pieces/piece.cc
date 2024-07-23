#include "piece.h"

Piece::Piece(string currPos, bool hasMoved, const string& colour, const char& symbol)
    : currPos(currPos), hasMoved(hasMoved), colour(colour), symbol(symbol) {}
