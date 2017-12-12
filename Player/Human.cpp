//
// Created by aymer on 12/12/2017.
//

#include <iostream>
#include "Human.h"

Human::Human() {
    this->setName("Human");
    this->setId('X');
}

std::vector<int> Human::getMove() {
    int x, y = -1;
    std::vector<int> move;
    while(x < 0 || x > 2 || y < 0 || y > 2) {
        // Loop until a valid move is entered
        std::cout << "Enter your move in coordinate form, ex: (1,3)." << std::endl;
        std::cout << "Your Move: ";
        char c;
        std::string restofline;
        std::cin >> c;
        x = c - '0' - 1;
        std::cin >> c;
        y = c - '0' - 1;
        getline(std::cin, restofline); // get garbage chars after move
    }
    move = {x, y};
    return move;
}