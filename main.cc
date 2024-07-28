#include <iostream>
#include <vector>
#include "game.h"
#include <utility>
#include "converter.h"
#include <string>

using namespace std;

const int KINGS_NEEDED = 1;

void printFinalScore(int blackScore, int whiteScore) {
    cout << "Final Score:" << endl;
    cout << "White: " << whiteScore << endl;
    cout << "Black: " << blackScore << endl;
}

int computerLevel(const string& computer) {
    if (computer == "computer[1]") return 1;
    else if (computer == "computer[2]") return 2;
    else if (computer == "computer[3]") return 3;
    else if (computer == "computer[4]") return 4;
    else return 0;
}

void displayBoard(const string initialBoard[8][8]) {
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            cout << initialBoard[i][j] << " ";
        }
        cout << endl;
    }
    cout << "  abcdefgh" << endl;
}

bool isValidCoord(const string& pos) {
    if (pos.length() != 2) return false;
    char col = pos[0];
    char row = pos[1];
    return (col >= 'a' && col <= 'h') && (row >= '1' && row <= '8');
}

bool isValidSetup(bool isBlackTurn, Game *game, const string board[8][8], int whiteKingCount, int blackKingCount) {
    if (whiteKingCount != KINGS_NEEDED) {
        cout << "WHITE MUST HAVE EXACTLY 1 KING" << endl;
        return false;
    }
    if (blackKingCount != KINGS_NEEDED) {
        cout << "BLACK MUST HAVE EXACTLY 1 KING" << endl;
        return false;
    }
    for (int i = 0; i < 8; i++) {
        if (board[0][i] == "P" || board[7][i] == "P") {
            return false;
        }
    }
    if (game->isGameOver(isBlackTurn)) {
        return false;
    }
    return true;
}

int main() {
    Game *game = nullptr;
    string initialBoard[8][8];
    bool gameRunning = false;
    int blackScore = 0, whiteScore = 0;
    bool isBlackTurn = false;
    string command;
    while (cin >> command) {
        if (command == "setup") {
            if (gameRunning) continue;
            gameRunning = true;
            isBlackTurn = false;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    initialBoard[i][j] = '_';
                }
            }
            string next;
            string colour = isBlackTurn ? "BLACK" : "WHITE";
            int whiteKingCount = 0, blackKingCount = 0;
            while (cin >> next) {
                if (next == "done") {
                    if (isValidSetup(isBlackTurn, game, initialBoard, whiteKingCount, blackKingCount)) {
                        break;
                    }
                    else cout << "Incorrect setup, you must rearrange some pieces!" << endl;
                } else if (next == "+") {
                    string piece, pos;
                    cin >> piece >> pos;
                    if (!isValidCoord(pos)) {
                        cout << "Invalid coordinate provided" << endl;
                        continue;
                    }
                    int row = 8 - (pos[1] - '0');
                    int col = pos[0] - 'a';
                    if (piece == "K") {
                        isBlackTurn ? ++blackKingCount : ++whiteKingCount;
                    }
                    if (game) {
                        game->removePiece(row, col);
                        game->addPiece(isBlackTurn, piece, row, col);
                    }
                    initialBoard[row][col] = piece;
                    displayBoard(initialBoard);
                } else if (next == "-") {
                    string pos;
                    cin >> pos;
                    if (!isValidCoord(pos)) {
                        cout << "Invalid coordinate provided" << endl;
                        continue;
                    }
                    int row = 8 - (pos[1] - '0');
                    int col = pos[0] - 'a';
                    if (initialBoard[row][col] == "_") continue;
                    if (game) {
                        game->removePiece(row, col);
                    }
                    initialBoard[row][col] = '_';
                    displayBoard(initialBoard);
                } else if (next == "=") {
                    cin >> colour;
                    isBlackTurn = (colour == "BLACK");
                }
            }
        } else if (command == "game") {
            if (gameRunning) {
                cout << "There is an ongoing game!" << endl; 
                continue;
            }
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
            game = new Game{p1, whiteComputerLevel, p2, blackComputerLevel};
        } else if (command == "resign") {
            if (gameRunning) {
                if (isBlackTurn) {
                    ++blackScore;
                } else {
                    ++whiteScore;
                }
                gameRunning = false;
            }
            continue;
        } else if (command == "move") {
            if (!gameRunning) {
                cout << "There is no game running!" << endl;
                continue;
            }
            isBlackTurn = !isBlackTurn;
            string startPos, endPos;
            cin >> startPos >> endPos;
            if (!isValidCoord(startPos) || !isValidCoord(endPos)) {
                cout << "Invalid coordinate provided" << endl;
                continue;
            }
            int startRow = 8 - (startPos[1] - '0');
            int startCol = startPos[0] - 'a';
            int endRow = 8 - (endPos[1] - '0');
            int endCol = endPos[0] - 'a';
            if (game && game->isValidMove(isBlackTurn, startRow, startCol, endRow, endCol)) {
                string movingPiece = initialBoard[startRow][startCol];
                initialBoard[startRow][startCol] = "_";
                initialBoard[endRow][endCol] = movingPiece;
                game->makeMove(isBlackTurn, startRow, startCol, endRow, endCol);
                if (game->isGameOver(isBlackTurn)) {
                    if (isBlackTurn) {
                        ++blackScore;
                    } else {
                        ++whiteScore;
                    }
                    gameRunning = false;
                    printFinalScore(blackScore, whiteScore);
                }
            } else {
                cout << "Invalid move" << endl;
            }
        }
    }
    delete game;
    return 0;
}
