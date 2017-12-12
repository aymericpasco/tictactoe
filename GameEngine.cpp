//
// Created by aymer on 12/12/2017.
//

#include <iostream>
#include <iomanip>
#include "GameEngine.h"


GameEngine::GameEngine(Human human, AI ai) {
    this->setupBoard();
    this->m_human = human;
    this->m_ai = ai;
}

void GameEngine::setupBoard() {
    this->m_board = std::vector<std::vector<char>>(3, std::vector<char>(3, 0));
    this->m_board = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
}

void GameEngine::printBoard() {
    std::cout << "-------------------";
    for(int i = 0; i < 3; i++) {
        std::cout << '\n' << "|";
        for(int j = 0; j < 3; j++) {
            std::cout << std::setw(3) << this->m_board[i][j] << std::setw(3) << " |";
        }
    }
    std::cout << '\n' << "-------------------" << '\n';
}

void GameEngine::play() {
    int turn = 0;
    printBoard();
    while(turn != 99) {
        // human move
        if(turn % 2 == 0) {
            std::vector<int> humanMove = m_human.getMove();
            this->m_board[humanMove[0]][humanMove[1]] = m_human.getId();
            turn++;
            printBoard();
        } else {
            std::cout << std::endl << "Computer Player Move:" << std::endl;
            //Move AImove = minimax(board);
            //board[AImove.x][AImove.y] = ai;
            std::vector<int> AIMove = m_ai.findBestMove(this->m_board);
            this->m_board[AIMove[0]][AIMove[1]] = this->m_ai.getId();
            //if(checkWin(AI)) cout << "Computer Player Wins" << endl;
            turn++;
            printBoard();
        }
    }
}