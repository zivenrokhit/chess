#ifndef Level2_H
#define Level2_H
#include "computer.h"
#include <string>

class Level2: public Computer {
    public:
        Level2(const string &, Game *);
        virtual ~Level2() override;
};

#endif

