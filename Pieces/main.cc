// this file is for testing purposes

#include "position.h"
#include <iostream>  // For std::cout and std::cerr

using std::cout;
using std::cerr;
using std::endl;
using std::exception;

int main() {
    try {
        Position pos(4, 6); // Represents "e7"
        Position posStr("e7");

        cout << "Position from coordinates: " << pos.toString() << endl; // Outputs: "e7"
        cout << "Position from string: " << posStr.toString() << endl; // Outputs: "e7"
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
