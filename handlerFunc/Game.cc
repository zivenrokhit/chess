#include "game.h"
#include "player.h"

Game::Game(bool isBlackTurn, 
            string whitePType, 
            int whitePLevel, 
            string blackPType, 
            int blackPLevel): isBlackTurn{isBlackTurn} 
    {
        if (whitePLevel == 0) {
            // this->whitePlayer =new  Human {"white"};
        } else if (whitePLevel == 1) {
            // this->whitePlayer = new Level1 {"white"};
        } else if (whitePLevel == 2) {
            // this->whitePlayer = new Level2 {"white"};
        } else if (whitePLevel == 3) {
            // this->whitePlayer = new Level3 {"white"};
        } else if (whitePLevel == 4) {
            // this->whitePlayer = new Level4 {"white"};
        }
        
        if (blackPLevel == 0) {
            // this->blackPlayer = new Human {"black"};
        } else if (blackPLevel == 1) {
            // this->blackPlayer = new Level1 {"black"};
        } else if (blackPLevel == 2) {
            // this->blackPlayer = new Level2 {"black"};
        } else if (blackPLevel == 3) {
            // this->blackPlayer = new Level3 {"black"};
        } else if (blackPLevel == 4) {
            // this->blackPlayer = new Level4 {"black"};
        }

}
bool Game::isGameRunning() {
    return true;
}
Game::~Game() {
    delete whitePlayer;
    delete blackPlayer;
}
