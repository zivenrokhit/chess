#include "board.h"
#include <utility>
#include <iostream>

using namespace std;

Board::Board(Game *game) : game(game) {
    cout << "in board ctor" << endl;
    // cout << game->blackPieces[0]->getColour() << endl;
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
    if (!this->whitePieces.empty()) {
        cout << "In white piece, king symbol is " << this->whitePieces[0]->getSymbol() << endl;
    } else {
        cout << "No white pieces available" << endl;
    }

    if (!this->blackPieces.empty()) {
        cout << "In black piece, king symbol is " << this->blackPieces[0]->getSymbol() << endl;
    } else {
        cout << "No black pieces available" << endl;
    }
    if (!this->whitePieces.empty()) {
        cout << "in white piece king symbol is " << this->whitePieces[0]->getSymbol() << endl;
    } else {
        cout << "No white pieces available" << endl;
    }
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
    if (!king) {
        cerr << "King not found!" << endl;
        return false;
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
    cout << "memLeak 1.9911" << endl;
    cout << "black pieces is : " << this->blackPieces.empty() << endl;
    for (auto piece : this->blackPieces) { // ISSUE HERE
        cout << "memLeak 2.1" << endl;
        if (piece->getSymbol() == "KING") return piece;
    }
    return nullptr;
    cout << "memLeak 1.991234" << endl;
}

bool Board::isWhiteChecked() {
    cout << "memLeak 1.99" << endl;
    Piece *whiteKing = this->getWhiteKing();
    if (!whiteKing) return false;
    pair<int, int> pos = whiteKing->getCurrPos();
    for (auto piece : this->blackPieces) {
        for (auto attack : piece->getMoves()) {
            if (pos == attack) return true;
        }
    }
    return false;
    cout << "memLeak 1.999909" << endl;
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
    cout << "memLeak 1.8" << endl;
    if (isBlackTurn) {
        return this->isStalemate(isBlackTurn) && this->isBlackChecked();
    }
    return this->isStalemate(isBlackTurn) && this->isWhiteChecked();
    cout << "memLeak 1.81" << endl;
}

bool Board::isStalemate(bool isBlackTurn) {
    cout << "memLeak 1.9" << endl;
    if (isBlackTurn) {
        Piece *blackKing = this->getBlackKing();
        for (auto move : blackKing->getMoves()) {
            if (!this->isSquareChecked(isBlackTurn, move.first, move.second)) {
                return false;
            }
        }
        return this->isBlackChecked() == false;
    }
    cout << "memLeak 1.91" << endl;
    Piece *whiteKing = this->getWhiteKing();
    for (auto move : whiteKing->getMoves()) {
        if (!this->isSquareChecked(isBlackTurn, move.first, move.second)) {
            return false;
        }
    }
    return this->isWhiteChecked() == false;
    cout << "memLeak 1.92" << endl;
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
