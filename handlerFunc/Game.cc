#include "game.h"
#include "player.h"
#include "human.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "king.h"

using namespace std;

Game::Game( string whitePType, 
            int whitePLevel, 
            string blackPType, 
            int blackPLevel): board{nullptr}
    {
        if (whitePLevel == 0) {
            this->whitePlayer = new Human {"white", this};
        } else if (whitePLevel == 1) {
            this->whitePlayer = new Level1 {"white", this};
        } else if (whitePLevel == 2) {
            this->whitePlayer = new Level2 {"white", this};
        } else if (whitePLevel == 3) {
            this->whitePlayer = new Level3 {"white", this};
        } else if (whitePLevel == 4) {
            this->whitePlayer = new Level4 {"white", this};
        }
        
        if (blackPLevel == 0) {
            this->blackPlayer = new Human {"black", this};
        } else if (blackPLevel == 1) {
            this->blackPlayer = new Level1 {"black", this};
        } else if (blackPLevel == 2) {
            this->blackPlayer = new Level2 {"black", this};
        } else if (blackPLevel == 3) {
            this->blackPlayer = new Level3 {"black", this};
        } else if (blackPLevel == 4) {
            this->blackPlayer = new Level4 {"black", this};
        }

}

void Game::addPiece(bool isBlackTurn, char symbol, int row, int col) {
    vector<pair<int, int>>tmp_moves;
    if (isBlackTurn) {
        if (symbol == 'P') {
            this->blackPieces.emplace_back(new Pawn{row, col, board, "BLACK", "P", tmp_moves});
        } else if (symbol == 'R') {
            this->blackPieces.emplace_back(new Rook{row, col, board, "BLACK", "R", tmp_moves, false});
        } else if (symbol == 'N') {
            this->blackPieces.emplace_back(new Knight{row, col, board, "BLACK", "N", tmp_moves});
        } else if (symbol == 'B') {
            this->blackPieces.emplace_back(new Bishop{row, col, board, "BLACK", "B", tmp_moves});
        } else if (symbol == 'Q') {
            this->blackPieces.emplace_back(new Queen{row, col, board, "BLACK", "Q", tmp_moves});
        } else if (symbol == 'K') {
            this->blackPieces.emplace_back(new King{row, col, board, "BLACK", "K", tmp_moves, false});
        }
    } else {
        if (symbol == 'P') {
            this->whitePieces.emplace_back(new Pawn{row, col, board, "WHITE", "P", tmp_moves});
        } else if (symbol == 'R') {
            this->whitePieces.emplace_back(new Rook{row, col, board, "WHITE", "R", tmp_moves, false});
        } else if (symbol == 'N') {
            this->whitePieces.emplace_back(new Knight{row, col, board, "WHITE", "N", tmp_moves});
        } else if (symbol == 'B') {
            this->whitePieces.emplace_back(new Bishop{row, col, board, "WHITE", "B", tmp_moves});
        } else if (symbol == 'Q') {
            this->whitePieces.emplace_back(new Queen{row, col, board, "WHITE", "Q", tmp_moves});
        } else if (symbol == 'K') {
            this->whitePieces.emplace_back(new King{row, col, board, "WHITE", "K", tmp_moves, false});
        }
    }
}
void Game::removePiece(int row, int col) {
    for (auto it = blackPieces.begin(); it != blackPieces.end(); ++it) {
        if ((*it)->getCurrPos() == make_pair(row, col)) {
            delete *it; // deletes piece from heap
            this->blackPieces.erase(it);
            break;
        }
    }
    for (auto it = whitePieces.begin(); it != whitePieces.end(); ++it) {
        if ((*it)->getCurrPos() == make_pair(row, col)) {
            delete *it; // deletes piece from heap
            this->whitePieces.erase(it);
            break;
        }
    }
}

bool Game::hasPiece(bool isBlackTurn, int row, int col) {
    if (isBlackTurn) {
        for (auto piece : this->blackPieces) {
            pair<int, int> coords = make_pair(row, col);
            if (piece->getCurrPos() == coords) return true;
        }
        return false;
    }
    for (auto piece : this->whitePieces) {
        pair<int, int> coords = make_pair(row, col);
        if (piece->getCurrPos() == coords) return true;
    }
    return false;
    
}

Piece *Game::getPiece(bool isBlackTurn, int row, int col) {
    if (isBlackTurn) {
        for (auto piece : this->blackPieces) {
            pair<int, int> coords = make_pair(row, col);
            if (piece->getCurrPos() == coords) return piece;
        }
    }
    for (auto piece : this->whitePieces) {
        pair<int, int> coords = make_pair(row, col);
        if (piece->getCurrPos() == coords) return piece;
    }
}


bool Game::isValidMove(bool isBlackTurn, int startRow, int startCol, int endRow, int endCol) {
    //check if player is moving a piece they own
    if (!this->hasPiece(isBlackTurn, startRow, startCol)) return false;
    // fetches piece
    Piece *movingPiece = this->getPiece(isBlackTurn, startRow, startCol);
    // checks if proposed move is in list of psuedo moves
    for (auto coords : movingPiece->getMoves()) {
        if (coords.first == endRow && coords.second == endCol) return true;
    }
    return false;
}

void Game::print() {
    this->board->printBoard();
}

void Game::updateAllPseudoMoves() {
    for (auto piece : this->whitePieces) {
        piece->setMoves();
    }
    for (auto piece : this->blackPieces) {
        piece->setMoves();
    }
}

void Game::makeMove(bool isBlackTurn, int startRow, int startCol, int endRow, int endCol) {
    // must check if move is valid first!!!
    // two cases: 1. piece moves to empty spot, 2. piece kills other piece

    // needs to update, 
    this->updateAllPseudoMoves();
    // remove piece still works if nothing is there
    this->removePiece(endRow, endCol);
    this->boardArr[endRow][endCol] = this->boardArr[startRow][startCol];
    this->boardArr[startRow][startCol] = '_';
    Piece *movingPiece = this->getPiece(isBlackTurn, startRow, startCol);
    movingPiece->setCurrentPos(endRow, endCol);
    this->updateAllPseudoMoves();
    this->board->printBoard();


}

bool Game::isGameOver() {
    return this->board->hasCheckmate() || this->board->hasStalemate();
}

Game::~Game() {
    delete boardArr; // maybe
    delete whitePlayer; 
    delete blackPlayer;
    for (auto piece : this->whitePieces) delete piece; 
    for (auto piece : this->blackPieces) delete piece; 
}
