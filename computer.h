#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include "player.h"

class Computer: public Player {
    public:
        virtual ~Computer() = 0;
};


#endif
