#include "board.h"


Board::Board(string board[8][8]) {

}

Board::~Board() {
    // for (auto o : this->observers) delete o;
    for (auto piece : this->whitePieces) delete piece;
    for (auto piece : this->blackPieces) delete piece;
}

bool Board::isCheck(bool isBlackTurn) {
    // Find the King
    Piece *king = nullptr;
    const vector<Piece *> &pieces = isBlackTurn ? blackPieces : whitePieces;
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
    const vector<Piece *> &opponentPieces = isBlackTurn ? whitePieces : blackPieces;
    for (Piece *opponentPiece : opponentPieces) {
        if (opponentPiece->canMove(king->getCurrPos())) {
            return true;
        }
    }

    return false;

}

void Board::printBoard() {
    this->notifyObservers();
}

