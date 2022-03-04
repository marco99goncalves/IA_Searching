#pragma once
#include <iostream>

#define WIDTH 2

class Game
{
public:
    int mat[WIDTH][WIDTH];
    Game(std::string game);
    void PrintGame();
    int GetInversionPolarity();
    bool operator==(Game *rhs);
};