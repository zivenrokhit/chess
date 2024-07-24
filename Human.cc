#include "human.h"

Human::Human(const string &colour, Game *game) {
    this->side = colour;
    this->game = game; //Human not responsible for deleting Game *
}


Human::~Human() {}

