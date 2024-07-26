#include "board.h"
#include <utility>
#include <iostream>

using namespace std;

Board::Board(Game *game) : game(game) {
    this->board = new string*[8];
    for (int i = 0; i < 8; ++i) {
        this->board[i] = new string[8];
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i >= 0 && i < 8 && j >= 0 && j < 8) {
                this->board[i][j] = game->boardArr[i][j];
            }
        }
    }
    this->whitePieces = game->whitePieces;
    this->blackPieces = game->blackPieces;

}


Board::~Board() {
    for (auto piece : this->whitePieces) delete piece;
    for (auto piece : this->blackPieces) delete piece;
}

bool Board::isCheck(bool isBlackTurn) {
    Piece *king = nullptr;
    const vector<Piece *> &pieces = isBlackTurn ? blackPieces : whitePieces;
    for (Piece *piece : pieces) {
        if (piece->getSymbol() == "KING") {
            king = piece;
            break;
        }
    }
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
    return nullptr;
}

Piece *Board::getBlackKing() {
    for (auto piece : this->blackPieces) { 
        if (piece->getSymbol() == "KING") return piece;
    }
    return nullptr;
}

bool Board::isWhiteChecked() {
    Piece *whiteKing = this->getWhiteKing();
    if (!whiteKing) return false;
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
    if (!blackKing) return false;
    pair<int, int> pos = blackKing->getCurrPos();
    for (auto piece : this->whitePieces) {
        for (auto attack : piece->getMoves()) {
            if (pos == attack) return true;
        }
    }
    return false;
}

bool Board::isSquareChecked(bool isBlackTurn, int row, int col) {
    pair<int, int> pos {row, col};
    vector<Piece *> candidatePieces = isBlackTurn ? this->whitePieces : this->blackPieces;
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
            if (!this->isSquareChecked(isBlackTurn, move.first, move.second)) {
                return false;
            }
        }
        return this->isBlackChecked() == false;
    }
    Piece *whiteKing = this->getWhiteKing();
    for (auto move : whiteKing->getMoves()) {
        if (!this->isSquareChecked(isBlackTurn, move.first, move.second)) {
            return false;
        }
    }
    return this->isWhiteChecked() == false;
}

Game *Board::getGame() {
    return this->game;
}

void Board::printBoard() {
    this->notifyObserver();
}

vector<Piece *> Board::getBlackPieces() {
    return this->blackPieces;
}

vector<Piece *> Board::getWhitePieces() {
    return this->whitePieces;
}
