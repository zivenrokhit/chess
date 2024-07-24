#ifndef Level1_H
#define Level1_H
#include <string>
#include "computer.h"

class Level1: public Computer {
    public:
        Level1(const string &, Game *);
        virtual ~Level1() override;
};

#endif

