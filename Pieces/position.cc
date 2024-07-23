#include "position.h"
#include <stdexcept>  // For std::out_of_range and std::invalid_argument

using std::out_of_range;
using std::invalid_argument;
using std::string;
using std::to_string;

Position::Position(int x, int y) : x(x), y(y) {
    if (!isValid()) {
        throw out_of_range("Invalid position coordinates");
    }
}

Position::Position(const string& pos) {
    if (pos.size() == 2 && pos[0] >= 'a' && pos[0] <= 'h' && pos[1] >= '1' && pos[1] <= '8') {
        x = pos[0] - 'a';
        y = pos[1] - '1';
    } else {
        throw invalid_argument("Invalid position string");
    }
}

string Position::toString() const {
    return string(1, 'a' + x) + to_string(1 + y);
}

bool Position::isValid() const {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
