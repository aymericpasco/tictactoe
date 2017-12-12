//
// Created by aymer on 12/12/2017.
//

#ifndef BOT_MORPION_PLAYER_H
#define BOT_MORPION_PLAYER_H

#include "string"

class Player {

private:
    char m_id;
    std::string m_name;

protected:
    void setId(char id);
    void setName(std::string name);

public:
    Player();

    char getId();
    std::string getName();

};


#endif //BOT_MORPION_PLAYER_H
