#ifndef Level4_H
#define Level4_H
#include "computer.h"
#include <string>

class Level4: public Computer {
    public:
        Level4(const string &, Game *);
        virtual ~Level4() override;
};

#endif

