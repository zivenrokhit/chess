#include "textobserver.h"
#include <string>

TextObserver::TextObserver(Board *sub): subject{sub}{
    subject->attach(this);
}

TextObserver::~TextObserver(){
    subject->detach(this);
}
void printCurrState(Board *sub) { // print the board out
    for(int i = 0; i < 8; i++){
        out << 8 - i << " ";
        for(int j = 0; j < 8; i++){
            out << subject->board[i][j]; /// not coorrect snytax
        }
        out << endl;
    }
    out << "\n  abcdefgh"<< endl;
    
}

void declareState(Board *sub){ // check for check, checkmate, stalemate
    if(subject->kingsOnly()){
        out << "Insufficint Material." << endl;
        out << "DRAW!" << endl;
    }else if(subject->inCheck("WHITE")){
        if(subject->inCheckmate("WHITE")){
            out << "Checkmate! Black wins!" << endl;
        } 
        out << "White is in check."
    } else if(subject->inCheck("BLACK")){
        if(subject->inCheckmate("BLACK")){
            out << "Checkmate! White wins!" << endl;
        } 
        out << "Black is in check."
    }else if(subject->inStalemate("WHITE") || subject->inStalemate("BLACK")){
        out << "Stalemate!" << endl;
    } else if (subject->resigned("WHITE")){
        out << "Black wins!" << endl;
    } else if(subject->resigned("BLACK")){
        out << "White wins!" << endl;
    }
}

void TextObserver::notify() override{
    printCurrState(subject);
    declareState(subject);
}
