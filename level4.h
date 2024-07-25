#ifndef Level4_H
#define Level4_H
#include <string>
#include "computer.h"

class Level4: public Computer {
    public:
        Level4(const string &, Game *);
        virtual ~Level4() override;
};

#endif

