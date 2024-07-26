#include "board.h"
#include <utility>

using namespace std;


Board::Board(string initBoard[8][8], Game *game)
    : game(game), whitePieces(game->whitePieces), blackPieces(game->blackPieces) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = initBoard[i][j];
        }
    }
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


Piece *Board::getWhiteKing() {
    for (auto piece : this->whitePieces) {
        if (piece->getSymbol() == "KING") return piece;
    }
}

Piece *Board::getBlackKing() {
    for (auto piece : this->blackPieces) {
        if (piece->getSymbol() == "KING") return piece;
    }
}


bool Board::isWhiteChecked() {
    Piece *whiteKing = this->getWhiteKing();
    pair<int, int> pos = whiteKing->getCurrPos();
    for (auto piece : this->blackPieces) {
        for (auto attack : piece->getMoves()) {
            if (pos == attack) return true;
        }
    }
    return false;
}
bool Board::isBlackChecked() {
    Piece *blackKing = this->getBlackKing();
    pair<int, int> pos = blackKing->getCurrPos();
    for (auto piece : this->blackPieces) {
        for (auto attack : piece->getMoves()) {
            if (pos == attack) return true;
        }
    }
    return false;
}
bool Board::isSquareChecked(bool isBlackTurn, int row, int col) {
    pair<int, int> pos {row, col};
    vector<Piece *>candidatePieces = isBlackTurn ? this->whitePieces : this->blackPieces;
    for (auto piece : candidatePieces) {
        for (auto attack : piece->getMoves()) {
            if (pos == attack) return true;
        }
    }
     return false;
}

bool Board::isCheckmate(bool isBlackTurn) {
    if (isBlackTurn) {
        return this->isStalemate(isBlackTurn) && this->isBlackChecked();
    }
    return this->isStalemate(isBlackTurn) && this->isWhiteChecked();
}


bool Board::isStalemate(bool isBlackTurn) {
    if (isBlackTurn) {
        Piece *blackKing = this->getBlackKing();
        for (auto move : blackKing->getMoves()) {
            if (!this->isSquareChecked(move.first, move.second)) {
                return false;
            }
        }
        return this->isBlackChecked() == false;
    }
    Piece *whiteKing = this->getWhiteKing();
    for (auto move : whiteKing->getMoves()) {
        if (!this->isSquareChecked(move.first, move.second)) {
            return false;
        }
    }
    return this->isWhiteChecked() == false;
}


Game *Board::getGame() {
    return this->game;
}

void Board::printBoard() {
    this->notifyObservers();
}


vector<Piece *> Board::getBlackPieces() {
    return this->blackPieces;
}
vector<Piece *> Board::getWhitePieces() {
    return this->whitePieces;
}


