#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"
#include "piece.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class Game {
    friend class Board;
    Player *whitePlayer; //initialized in ctor
    Player *blackPlayer; //initialized in ctor
    vector<Piece *> whitePieces; // add/remove as you go in setup
    vector<Piece *> blackPieces; // add/remove as you go in setup
    string boardArr[8][8];
    Board *board;
    // bool isWhiteChecked;
    // bool isBlackChecked;
public: 
    Game(string whitePType, int whitePLevel,
         string blackPType, int blackPLevel); // done
    void addPiece(bool isBlackTurn, string symbol, int row, int col); // done
    Piece *removePiece(int row, int col); //done 
    bool hasPiece(bool isBlackTurn, int row, int col); // done
    Piece *getPiece(bool isBlackTurn, int row, int col); //done
    ~Game(); // must itr through pieces and delete off heap
    bool isValidMove(bool isBlackTurn, int startRow, int startCol, int endRow, int endCol); //done
    void makeMove(bool isBlackTurn, int startRow, int startCol, int endRow, int endCol); // done
    bool isGameOver(bool); // done
    void print(); //done 
    void updateAllPseudoMoves();
};

#endif // GAME_H
