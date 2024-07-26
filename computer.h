#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include <string>

class Computer: public Player {
    public:
        virtual ~Computer() = 0;
};


#endif
