//
// Created by aymer on 12/12/2017.
//

#include <windef.h>
#include <bits/stdc++.h>
#include "AI.h"

AI::AI() {
    this->setName("AI");
    this->setId('O');
}

std::vector<int> AI::findBestMove(std::vector<std::vector<char>> board) {
    int bestVal = -1000;
//    Move bestMove;
//    bestMove.row = -1;
//    bestMove.col = -1;
    this->m_move = {-1, -1};

    // Traverse all cells, evalutae minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if celll is empty
            if (board[i][j]=='-')
            {
                // Make the move
                board[i][j] = 'O';

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);

                // Undo the move
                board[i][j] = '-';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
//                    bestMove.row = i;
//                    bestMove.col = j;
                    this->m_move = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }

//    printf("The value of the best Move is : %dnn",
//           bestVal);

    return this->m_move;
}

int AI::minimax(std::vector<std::vector<char>> board, int depth, bool isMax) {
    int score = this->evaluate(board);

    if (score == 10) return score;
    if (score == -10) return score;
    if (!this->isMovesLeft(board)) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                    best = std::max (best, this->minimax(board, depth+1, !isMax));
                    board[i][j] = '-';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == '-') {
                    board[i][j] = 'X';
                    best = std::min (best, minimax(board, depth+1, !isMax));
                    board[i][j] = '-';
                }
            }
        }
        return best;
    }
}

int AI::evaluate(std::vector<std::vector<char>> b) {
    for (int row = 0; row < 3; ++row) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == 'O') return +10;
            else if (b[row][0] == 'X') return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]=='O')
                return +10;

            else if (b[0][col]=='X')
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]=='O')
            return +10;
        else if (b[0][0]=='X')
            return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]=='O')
            return +10;
        else if (b[0][2]=='X')
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}

bool AI::isMovesLeft(std::vector<std::vector<char>> board) {
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='-')
                return true;
    return false;
}