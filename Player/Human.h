//
// Created by aymer on 12/12/2017.
//

#ifndef BOT_MORPION_HUMAN_H
#define BOT_MORPION_HUMAN_H


#include <vector>
#include "../Player.h"

class Human : public Player {

public:
    Human();

    std::vector<int> getMove();

};


#endif //BOT_MORPION_HUMAN_H
