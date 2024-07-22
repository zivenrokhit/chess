#include "player.h"
#include <string>
#include <vector>

using namespace std;

class Game {
    Player *whitePlayer;
    Player *blackPlayer;
    bool isBlackTurn;
    //Board board;
    public: 
        Game(bool isBlackTurn, string whitePType, int whitePLevel, string blackPType, int blackPLevel);
        ~Game();
        void start();
        bool isValidMove();
        void makeMove();
        bool isGameRunning();
        void print();

};


