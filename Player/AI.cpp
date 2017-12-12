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

    for (int i = 0; i < 3; ++i) {
        if (b[i][0] == b[i][1] and b[i][1] == b[i][2]) {
            if (b[i][0] == 'O') return +10;
            else if (b[i][0] == 'X') return -10;
        }
        if (b[0][i] == b[1][i] and b[1][i] == b[2][i]) {
            if (b[0][i] == 'O') return +10;
            else if (b[0][i] == 'X') return -10;
        }
    }

    if (b[0][0] == b[1][1] and b[1][1] == b[2][2]) {
        if (b[0][0] == 'O') return +10;
        else if (b[0][0] == 'X') return -10;
    }

    if (b[0][2] == b[1][1] and b[1][1] == b[2][0]) {
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