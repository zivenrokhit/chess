#ifndef CONVERTER_H
#define CONVERTER_H
#include <utility>
#include <string>

using namespace std;

class Converter {
    public:
        //coord is of the form [a-h][1-8]
        // use like this Converter::coordToIdx("h8") => 7, 7
        static pair<int, int>coordToIdx(const string &);
        // pair of the form ([0-7], [0-7])
        // use like this Converter::idxToCoord((7, 7)) => "h8"
        static string idxToCoord(const pair<int, int> &);

};


#endif
