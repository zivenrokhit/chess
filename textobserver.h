#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H
#include "board.h"
#include <iostream>
#include <utility>
#include "observer.h"

using namespace std;

class TextObserver: public Observer {
    private:
    Board *subject;
    public:
    explicit TextObserver(Board *sub);
    ~TextObserver();
    void notify();
    void printCurrState();
    void declareState();
};

#endif
