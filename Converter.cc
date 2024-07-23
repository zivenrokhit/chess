#include "converter.h"
#include <iostream>

 pair<int, int> Converter::coordToIdx(const  string& coord) {
     pair<int, int> idx;
    if (coord.length() != 2 || coord[0] < 'a' || coord[0] > 'h' || coord[1] < '1' || coord[1] > '8') {
        idx.first = -1;
        idx.second = -1;
         cout << "Invalid coordinate: " << coord << endl; 
    } else {
        idx.first = coord[0] - 'a';
        idx.second = coord[1] - '1';
    }
    return idx;
}

string Converter::idxToCoord(const pair<int, int>& idx) {
    string coord;
    if (idx.first < 0 || idx.first > 7 || idx.second < 0 || idx.second > 7) {
        coord = "invalid";
         cout << "Invalid index: (" << idx.first << ", " << idx.second << ")" <<  endl; 
    } else {
        coord = static_cast<char>(idx.first + 'a');
        coord += static_cast<char>(idx.second + '1');
    }
    return coord;
}
