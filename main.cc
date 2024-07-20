#include <iostream>
#include <vector>
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

bool isValidMove(Game *gamePtr, bool isBlackTurn, string startPos, string endPos) {

}
int main() {
    // vector<Observer *> allObservers; //creates observers
    // Game *game = nullptr
    bool gameRunning = false;
    int blackScore = 0, whiteScore = 0;
    bool isBlackTurn = false;
    string command;
    while (cin >> command) {
        // if (game.isOver()) {isBlackTurn == true ?  ++blackScore : ++whiteScore;}
        if (command == "setup") {

        }
        if (command == "game") {
            if (gameRunning) {
                cout << "there is an ongoing game!" << endl; 
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
            // delete game;
            // game = new Game{};
            // game.start(p1, whiteComputerLevel, p2, blackComputerLevel);
        }
        if (command == "resign") {
            if (gameRunning) {
                isBlackTurn == true ?  ++blackScore : ++whiteScore;
                //game.end()
            }
            continue;
        }
        if (command == "move") {

            isBlackTurn = !isBlackTurn;
            // game.move()
        }
    }
    printFinalScore(blackScore, whiteScore);
    // for (auto o : allObservers) delete o;
    return 0;
}



