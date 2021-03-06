//
// Created by aymer on 12/12/2017.
//

#ifndef BOT_MORPION_GAMEENGINE_H
#define BOT_MORPION_GAMEENGINE_H


#include <vector>
#include "Player/Human.h"
#include "Player/AI.h"

class GameEngine {

public:
    GameEngine(Human human, AI ai);

    void play();

private:
    std::vector<std::vector<char>> m_board;

    Human m_human;
    AI m_ai;

    void setupBoard();

    void printBoard();

    bool checkWin(Player player);
    bool gameOver();
};


#endif //BOT_MORPION_GAMEENGINE_H
