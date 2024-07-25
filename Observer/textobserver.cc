#include "textobserver.h"
#include <iostream>
#include <string>

using namespace std;

TextObserver::TextObserver(Board *sub): subject{sub}{
    subject->attach(this);
}

TextObserver::~TextObserver(){
    subject->detach(this);
}
void printCurrState(Board *sub) { // print the board out
    for(int i = 0; i < 8; i++){
        cout << 8 - i << " ";
        for(int j = 0; j < 8; i++){
            cout << subject->board[i][j];
        }
        cout << endl;
    }
    cout << "\n  abcdefgh"<< endl;
    
}

void declareState(Board *sub){ // check for check, checkmate, stalemate
    if(subject->kingsOnly()){
        cout << "Insufficint Material." << endl;
        cout << "DRAW!" << endl;
    }else if(subject->inCheck("WHITE")){
        if(subject->inCheckmate("WHITE")){
            cout << "Checkmate! Black wins!" << endl;
        } 
        cout << "White is in check."
    } else if(subject->inCheck("BLACK")){
        if(subject->inCheckmate("BLACK")){
            cout << "Checkmate! White wins!" << endl;
        } 
        cout << "Black is in check."
    }else if(subject->inStalemate("WHITE") || subject->inStalemate("BLACK")){
        cout << "Stalemate!" << endl;
    } else if (subject->resigned("WHITE")){
        cout << "Black wins!" << endl;
    } else if(subject->resigned("BLACK")){
        cout << "White wins!" << endl;
    }
}

void TextObserver::notify() override{
    printCurrState(subject);
    declareState(subject);
}
