#include <iostream>
#include "GameEngine.h"

using namespace std;

int main() {

    Human human;
    AI ai;

    GameEngine tictactoe(human, ai);

    tictactoe.play();

    return 0;
}