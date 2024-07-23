#ifndef POSITION_H
#define POSITION_H

#include <string>

using std::string;

class Position {
public:
    int x; // 0-7 for 'a'-'h'
    int y; // 0-7 for '1'-'8'

    Position(int x, int y);
    Position(const string& pos);

    string toString() const;
    bool isValid() const;
};

#endif // POSITION_H
