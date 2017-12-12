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

// GameEngine::~GameEngine(void) = default;

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

    while(!this->checkWin(this->m_human) && !this->checkWin(this->m_ai) && !this->gameOver()) {
        if(turn % 2 == 0) {
            std::vector<int> humanMove = m_human.getMove();
            this->m_board[humanMove[0]][humanMove[1]] = m_human.getId();
            if(checkWin(this->m_human)) std::cout << "Oops, you win.. ?!" << std::endl;
            turn++;
            printBoard();
        } else {
            std::cout << std::endl << "Computer:" << std::endl;
            std::vector<int> AIMove = m_ai.findBestMove(this->m_board);
            this->m_board[AIMove[0]][AIMove[1]] = this->m_ai.getId();
            if(checkWin(this->m_ai)) std::cout << "Lol, you lose ;-)" << std::endl;
            turn++;
            printBoard();
        }
    }
}

bool GameEngine::checkWin(Player player) {
    char id = player.getId();

    for (int i = 0; i < 3; ++i) {
        // horizontal
        if(this->m_board[i][0] == id && this->m_board[i][1] == id
           && this->m_board[i][2] == id)
            return true;

        // vertical
        if(this->m_board[0][i] == id && this->m_board[1][i] == id
           && this->m_board[2][i] == id)
            return true;
    }

    // diagonal
    if (this->m_board[0][0] == id && this->m_board[1][1] == id
        && this->m_board[2][2] == id) {
        return true;
    } else if (this->m_board[0][2] == id && this->m_board[1][1] == id
               && this->m_board[2][0] == id) {
        return true;
    }

    return false;
}

bool GameEngine::gameOver() {
    if(checkWin(this->m_human)) return true;
    else if(checkWin(this->m_ai)) return true;

    bool emptySpace = false;

    for(int i = 0; i < 3; i++) {
        if(this->m_board[i][0] == '-' || this->m_board[i][1] == '-' || this->m_board[i][2] == '-')
            emptySpace = true;
    }
    return !emptySpace;
}