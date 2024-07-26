#ifndef Level3_H
#define Level3_H
#include "computer.h"
#include <string>

class Level3: public Computer {
    public:
        Level3(const string &, Game *);
        virtual ~Level3() override;
};

#endif

