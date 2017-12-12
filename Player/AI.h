//
// Created by aymer on 12/12/2017.
//

#ifndef BOT_MORPION_AI_H
#define BOT_MORPION_AI_H


#include <vector>
#include "../Player.h"

class AI : public Player {

public:
    AI();

    std::vector<int> findBestMove(std::vector<std::vector<char>> board);

    int minimax(std::vector<std::vector<char>> board, int depth, bool isMax);
    int evaluate(std::vector<std::vector<char>> b);
    bool isMovesLeft(std::vector<std::vector<char>> board);

private:
    std::vector<int> m_move;

};


#endif //BOT_MORPION_AI_H
