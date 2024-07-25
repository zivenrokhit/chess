#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
#include <string>

using namespace std;


class Human: public Player {
    public:
        Human(const string &, Game *);
        ~Human() override;
};

#endif


