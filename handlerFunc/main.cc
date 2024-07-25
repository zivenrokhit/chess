#include <iostream>
#include <vector>
#include "game.h"
#include <string>
#include <utility>
#include "converter.h"

using namespace std;

const int KINGS_NEEDED = 1;

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

bool isValidSetup(Game *game, char board[8][8], int whiteKingCount, int blackKingCount) {
// no pawns in first or last row, 1 king each, no one in check
    if (whiteKingCount != KINGS_NEEDED) {
        cout << "WHITE MUST HAVE EXACTLY 1 KING" << endl;
        return false;
    }
    if (blackKingCount != KINGS_NEEDED) {
        cout << "BLACK MUST HAVE EXACTLY 1 KING" << endl;
        return false;
    }
    for (int i = 0; i < 8; i++) {
        if (board[0][i] == 'P' || board[7][i] == 'P') {
            cout << "YOU CANNOT HAVE PAWNS IN THE FIRST OR LAST ROW" << endl;
            return false;
        }
    }
    // if (game->isCheck()); CHECK FOR IN CHECK KINGS
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
            isBlackTurn = false; //start on white
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    initialBoard[i][j] = '_';
                }
            }
            string next;
            string colour = isBlackTurn ? "black" : "white";
            int whiteKingCount = 0, blackKingCount = 0;
            while (cin >> next) {
                if (next == "done") {
                    if (isValidSetup(game, initialBoard, whiteKingCount, blackKingCount)) break;
                    else cout << "incorrect setup, you must rearrange some pieces!\n";
                } else if (next == "+") {
                    int row, col;
                    char piece;
                    string pos;
                    cin >> piece >> pos;
                    // checking for invalid input or bounds
                    if (pos.length() != 2 || pos[0] < 'a' || pos[0] > 'h' || pos[1] <= '0' || pos[1] >= '9') {
                        cout << "input was out of board bounds \n";
                        continue;
                    }
                    if (piece == 'K') {
                        isBlackTurn ? ++blackKingCount : ++whiteKingCount;
                    }
                    row = pos[1] - '1';
                    col = pos[0] - 'a';
                    game->removePiece(row, col);
                    game->addPiece(isBlackTurn, piece, row, col);
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
                    row = pos[0] - '1';
                    col = pos[1] - 'a';
                    if (initialBoard[row][col] == '_') continue;
                    game->removePiece( row, col);
                    initialBoard[row][col] = '_';
                    displayBoard(initialBoard);
                } else if (next == "=") {
                    cin >> colour;
                    isBlackTurn = (colour == "BLACK" ? true : false);
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
            // all it does is initialize player
            game = new Game{p1, whiteComputerLevel, p2, blackComputerLevel};
        }
        else if (command == "resign") {
            if (gameRunning) {
                isBlackTurn == true ?  ++blackScore : ++whiteScore;
                //game.end()
            }
            continue;
        }
        else if (command == "move") {
            if (!gameRunning) {
                cout << "there is no game running!" << endl;
                continue;
            }
            isBlackTurn = !isBlackTurn;
            string startPos, endPos;
            char pawnPromo = '-1';
            cin >> startPos >> endPos;
            int startRow = startPos[0] - '1';
            int startCol = startCol[1] - 'a';
            if (startPos.length() != 2 || pos[0] < 'a' || pos[0] > 'h' || pos[1] <= '0' || pos[1] >= '9') {
                cout << "input was out of board bounds \n";
                continue;
            }
            if (initialBoard[startCoords.first][startCoords.second] == '_') {
                cout << "Cannot move empty square" << endl;
                continue;
            }
            if (game->isValidMove(isBlackTurn, startPos, endPos)) {
                initialBoard[startCoords.first][startCoords.second] == '_';
                game->removePiece()
            }
            //consider pawn promotion if have time
            // if (game.isValidMove(isBlackTurn, startPos, endPos)) {
            //     game.makeMove(isBlackTurn, startPos, endPos);
            // } else {
            //     cout << "INVALID MOVE MONKEY BOY!" << endl;
            // }
        }
    }
    printFinalScore(blackScore, whiteScore);
    // for (auto o : allObservers) delete o;
    return 0;
}



