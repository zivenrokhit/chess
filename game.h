#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"
#include "piece.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class Board;
class Piece;

class Game {
    friend class Board;
    friend class Level1;
    Player *whitePlayer;
    Player *blackPlayer; 
    vector<Piece *> whitePieces; 
    vector<Piece *> blackPieces; 
    string** boardArr;
    Board *board;
public: 
    Game(string whitePType, int whitePLevel,
         string blackPType, int blackPLevel); // done
    void addPiece(bool isBlackTurn, string symbol, int row, int col); // done
    Piece *removePiece(int row, int col); // done
    bool hasPiece(bool isBlackTurn, int row, int col); // done
    Piece *getPiece(bool isBlackTurn, int row, int col); // done
    ~Game(); 
    bool isValidMove(bool isBlackTurn, int startRow, int startCol, int endRow, int endCol); // done
    void makeMove(bool isBlackTurn, int startRow, int startCol, int endRow, int endCol); // done
    bool isGameOver(bool); // done
    void print(); // done
    void updateAllPseudoMoves();
};

#endif // GAME_H
