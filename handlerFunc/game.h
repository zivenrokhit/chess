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
    // friend class Player;
    Player *whitePlayer; //initialized in ctor
    Player *blackPlayer; //initialized in ctor
    vector<Piece *> whitePieces; // add/remove as you go in setup
    vector<Piece *> blackPieces; // add/remove as you go in setup
    string boardArr[8][8];
    Board *board;
public: 
    Game(string whitePType, int whitePLevel,
         string blackPType, int blackPLevel); // done
    void addPiece(bool isBlackTurn, char symbol, int row, int col);
    void removePiece(int row, int col);
    ~Game(); // must itr through pieces and delete off heap
    bool isValidMove(bool isBlackTurn, string startPos, string endPos);
    void start();
    void makeMove(bool isBlackTurn, string startPos, string endPos);
    bool isGameRunning();
    void print();
    void resign();
};

#endif // GAME_H
