#include "player.h"
#include "piece.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class Game {
    // friend class Player;
    Player *whitePlayer;
    Player *blackPlayer;
    vector<Piece *>whitePieces;
    vector<Piece *>blackPieces;
    string boardArr[8][8];
    //Board board;
    public: 
        Game(string whitePType, int whitePLevel, vector<Piece *>whitePieces ,string blackPType, int blackPLevel,
                 vector<Piece *>blackPieces);
        ~Game();
        bool isValidMove(bool isBlackTurn, string startPos, string endPos);
        void start();
        void makeMove(bool isBlackTurn, string startPos, string endPos);
        bool isGameRunning();
        void print();
        void resign();

};


