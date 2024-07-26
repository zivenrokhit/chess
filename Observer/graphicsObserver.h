#ifndef GRAPHICSOBSERVER_H
#define GRAPHICSOBSERVER_H
#include "board.h"
#include "window.h"
#include <iostream>
#include "observer.h"
#include <vector>

using namespace std;

class GraphicsObserver : public Observer {
    Board *subject;
    int width = 0
    int height = 0;
    Xwindow *window;
    vector<vector<char>> current_state;
    const int SQUARE_WIDTH = 100;
    const int SQUARE_HEIGHT = 100;
    const int VERTICAL_PADDING = 10; 
    const int HORIZONTAL_PADDING = 10;
    const int PADDING_LEFT = 30;
    const int PADDING_BOTTOM = 30;
    public:
    GraphicsObserver(Board *s);
    ~GraphicsObserver();
    void notify() override;
    
};


#endif
