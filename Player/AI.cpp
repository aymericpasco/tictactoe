//
// Created by aymer on 12/12/2017.
//

//#include <windef.h>
//#include <bits/stdc++.h>
#include "AI.h"

AI::AI() {
    this->setName("AI");
    this->setId('O');
}

std::vector<int> AI::findBestMove(std::vector<std::vector<char>> board) {
    int bestVal = -1000;
    this->m_move = {-1, -1};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '-') {
                board[i][j] = this->getId();
                int moveVal = this->minimax(board, 0, false);
                board[i][j] = '-';

                if (moveVal > bestVal) {
                    this->m_move = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return this->m_move;
}

int AI::minimax(std::vector<std::vector<char>> board, int depth, bool isMax) {
    int score = this->evaluate(board);
    int best = 1000;

    if (score == 10 || score == -10) return score;
    if (!this->isMovesLeft(board)) return 0;

    if (isMax) best = -1000;
    //else best = 1000;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '-') {
                if (isMax) {
                    board[i][j] = this->getId();
                    best = std::max (best, this->minimax(board, depth + 1, !isMax));
                } else {
                    board[i][j] = 'X';
                    best = std::min (best, this->minimax(board, depth+1, !isMax));
                }
                board[i][j] = '-';
            }
        }
    }
    return best;
}

int AI::evaluate(std::vector<std::vector<char>> b) {
    for (int row = 0; row < 3; ++row) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == 'O') return +10;
            else if (b[row][0] == 'X') return -10;
        }
    }

    for (int col = 0; col<3; ++col) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
            if (b[0][col] == 'O') return +10;
            else if (b[0][col] == 'X') return -10;
        }
    }

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == 'O') return +10;
        else if (b[0][0] == 'X') return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == 'O') return +10;
        else if (b[0][2] == 'X') return -10;
    }

    return 0;
}

bool AI::isMovesLeft(std::vector<std::vector<char>> board) {
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='-')
                return true;

    return false;
}