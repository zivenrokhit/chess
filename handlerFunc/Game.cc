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
    if (isBlackTurn) {
        if (symbol == 'P') {
            //ctor params, row, col, board *, colour, symbol, 
            this->blackPieces.emplace_back(new Pawn{row, col, board, "BLACK", 'P'});
        } else if (symbol == 'R') {
            this->blackPieces.emplace_back(new Rook{row, col, board, "BLACK", 'R'});
        } else if (symbol == 'N') {
            this->blackPieces.emplace_back(new Knight{row, col, board, "BLACK", 'N'});
        } else if (symbol == 'B') {
            this->blackPieces.emplace_back(new Bishop{row, col, board, "BLACK", 'B'});
        } else if (symbol == 'Q') {
            this->blackPieces.emplace_back(new Queen{row, col, board, "BLACK", 'Q'});
        } else if (symbol == 'K') {
            this->blackPieces.emplace_back(new King{row, col, board, "BLACK", 'K'});
        }
    } else {
        if (symbol == 'P') {
            this->whitePieces.emplace_back(new Pawn{...});
        } else if (symbol == 'R') {
            this->whitePieces.emplace_back(new Rook{...});
        } else if (symbol == 'N') {
            this->whitePieces.emplace_back(new Knight{...});
        } else if (symbol == 'B') {
            this->whitePieces.emplace_back(new Bishop{...});
        } else if (symbol == 'Q') {
            this->whitePieces.emplace_back(new Queen{...});
        } else if (symbol == 'K') {
            this->whitePieces.emplace_back(new King{...});
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

bool Game::isGameRunning() {
}
Game::~Game() {
    delete whitePlayer; 
    delete blackPlayer;
    for (auto piece : this->whitePieces) delete piece; 
    for (auto piece : this->blackPieces) delete piece; 
}
