#include <iostream>
#include <vector>
#include "game.h"
#include <string>

using namespace std;

void printFinalScore(int blackScore, int whiteScore) {
        cout << "Final Score:" << endl;
        cout << "White: " << whiteScore << endl;
        cout << "Black: " << blackScore << endl;
}

int computerLevel(string computer) {
    if(computer == "computer[1]") return 1;
    else if(computer == "computer[2]") return 2;
    else if(computer == "computer[3]") return 3;
    else if (computer == "computer[4]") return 4;
    else return 0;
}

void displayBoard(char initialBoard[8][8]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << initialBoard[i][j];
        }
        cout << endl;
    }
}

//possibly a Game method?
bool isValidMove(Game *gamePtr, bool isBlackTurn, string startPos, string endPos) {

}

bool isValidSetup(char board[8][8]) {

}


int main() {
    // vector<Observer *> allObservers; //creates observers
    Game *game = nullptr;
    char initialBoard[8][8];
    bool gameRunning = false;
    int blackScore = 0, whiteScore = 0;
    bool isBlackTurn = false;
    string command;
    while (cin >> command) {
        if (game && !game->isGameRunning()) {
            isBlackTurn == true ?  ++blackScore : ++whiteScore;
            gameRunning = false;
        }
        if (command == "setup") {
            if (gameRunning) continue;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    initialBoard[i][j] = '_';
                }
            }
            string next;
            string colour = "white";
            while (cin >> next) {
                if (next == "done") {
                    if (isValidSetup(initialBoard)) break;
                    else cout << "incorrect setup, you must rearrange some pieces!\n";
                } else if (next == "+") {
                    int row, col;
                    char piece;
                    string pos;
                    cin >> piece >> pos;
                    if (pos.length() != 2 || pos[0] < 'a' || pos[0] > 'h' || pos[1] <= '0' || pos[1] >= '9') {
                        cout << "input was out of board bounds \n";
                        continue;
                    }
                    row = pos[1] - '1';
                    col = pos[0] - 'a';
                    initialBoard[row][col] = piece;
                    displayBoard(initialBoard);
                } else if (next == "-") {
                    string pos;
                    int row, col;
                    cin >> pos;
                    if (pos.length() != 2 || pos[0] < 'a' || pos[0] > 'h' || pos[1] <= '0' || pos[1] >= '9') {
                        cout << "input was out of board bounds \n";
                        continue;
                    }
                    row = pos[1] - '1';
                    col = pos[0] - 'a';
                    if (initialBoard[row][col] == '_') continue;
                    initialBoard[row][col] = '_';
                    displayBoard(initialBoard);
                } else if (next == "=") {
                    cin >> colour;
                }
            }
        }
        else if (command == "game") {
            if (gameRunning) {
                cout << "there is an ongoing game!" << endl; 
                continue;
            }
            //make seperate logic for computer interpreter
            isBlackTurn = false;
            string p1, p2;
            int whiteComputerLevel = 0;
            int blackComputerLevel = 0;
            cin >> p1 >> p2;
            if (p1 != "human") {
                whiteComputerLevel = computerLevel(p1);
            }
            if (p2 != "human") {
                blackComputerLevel = computerLevel(p2);
            }
            delete game;
            //add in the pieces map for both colours
            game = new Game{isBlackTurn, p1, whiteComputerLevel, p2, blackComputerLevel};
            // game.start(p1, whiteComputerLevel, p2, blackComputerLevel);
        }
        else if (command == "resign") {
            if (gameRunning) {
                isBlackTurn == true ?  ++blackScore : ++whiteScore;
                //game.end()
            }
            continue;
        }
        else if (command == "move") {
            isBlackTurn = !isBlackTurn;
            string startPos, endPos;
            char pawnPromo;
            cin >> startPos >> endPos;
            //consider pawn promotion if have time
            if (game.isValidMove(isBlackTurn, startPos, endPos)) {
                game.makeMove();
            } else {
                cout << "INVALID MOVE MONKEY BOY!" << endl;
            }
        }
    }
    printFinalScore(blackScore, whiteScore);
    // for (auto o : allObservers) delete o;
    return 0;
}



