#pragma once
#include <iostream>

#define WIDTH 3

class Game
{
public:
    int mat[WIDTH][WIDTH];
    Game(std::string game);
    void PrintGame();
    int GetInversionPolarity();
    bool operator==(Game *rhs);
};