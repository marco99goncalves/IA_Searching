#include <iostream>
#include "Game.h"

// g++ -Wall -o main main.cpp && ./main

int main()
{
    Game startState("3 4 2 5 1 7 6 0 8"); // inv = 7
    Game finalState("1 2 3 8 1 4 7 6 5"); // inv = 7

    // Check for solvability before doing anything else
    if (startState.GetInversionPolarity() != finalState.GetInversionPolarity())
    {
        std::cout << "Impossible :( \n";
        return 1;
    }

    return 0;
}