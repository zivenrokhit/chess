#include "board.h"


Board::Board()

Board::~Board() {
    for (auto o : this->observers) delete o;
    for (auto piece : this->whitePieces) delete piece;
    for (auto piece : this->blackPieces) delete piece;
}





