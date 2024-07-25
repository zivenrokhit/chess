#include "board.h"


Board::Board()

Board::~Board() {
    for (auto o : this->observers) delete o;
    for (auto piece : this->whitePieces) delete piece;
    for (auto piece : this->blackPieces) delete piece;
}

bool Board::isCheck() {
    // Find the King
    Piece *king = nullptr;
    const vector<Piece *> &pieces = (color == "WHITE") ? whitePieces : blackPieces;
    for (Piece *piece : pieces) {
        if (piece->getSymbol() == "KING") {
            king = piece;
            break;
        }
    }
    if (!king) {
        cerr << "King not found!" << endl;
        return false;
    }
    int kingRow = (king->getCurrPos()).first;
    int kingCol = (king->getCurrPos()).second;

    // Check all opponent pieces to see if any can move to the King's position
    const vector<Piece *> &opponentPieces = (color == "WHITE") ? blackPieces : whitePieces;
    for (Piece *opponentPiece : opponentPieces) {
        if (opponentPiece->canMove(king->getCurrPos())) {
            canMove(const pair<int,int> endPos, const vector<pair<int,int>> vecEndPos)
            return true;
        }
    }

    return false;

}




