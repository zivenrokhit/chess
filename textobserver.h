#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H
// the goal of this file it declare the required class and methods to output the text display of the board 
#include "board.h"
#include <iostream>
#include <utility>
#include "observer.h"

using namespace std;

class TextObserver {
    private:
    Board *subject;
    public:
    explicit TextObserver(Board *s);
    ~TextObserver();
    void notify() override;
};

#endif
