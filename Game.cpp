
#include <iostream>
#include <algorithm>
#include "Game.h"

#define WIDTH 2

int mat[WIDTH][WIDTH];

// Creates a new game
Game::Game(std::string game)
{
    int num = 0;
    int bytesConsumedNow = 0, bytesConsumedTotal = 0;

    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            sscanf(game.c_str() + bytesConsumedTotal, "%d%n", &num, &bytesConsumedNow);
            bytesConsumedTotal += bytesConsumedNow;
            mat[row][col] = num;
        }
    }
}

void Game::PrintGame()
{
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            std::cout << mat[row][col] << " ";
        }

        std::cout << "\n";
    }
    std::cout << "--\n";
}

// Codigo horrivel, mas é meio irrelevante portanto podemos ignorar por agora.
// Pior das hipoteses fazemos 2 * WIDTH^2 no programa inteiro.
int Game::GetInversionPolarity()
{
    int nums[WIDTH * WIDTH];

    int count = 0;
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            nums[count++] = mat[row][col];
        }
    }

    int inversions = 0;
    for (int i = 0; i < WIDTH * WIDTH; i++)
    {
        for (int j = i + 1; j < WIDTH * WIDTH; j++)
        {
            if (nums[j] < nums[i] && nums[j] != 0 && nums[i] != 0)
                inversions++;
        }
    }
    return inversions % 2;
}

// Compares two games to see if theyre equal
// Passed by reference for efficiency
bool Game::operator==(Game *rhs)
{
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            if (mat[row][col] != rhs->mat[row][col])
                return false;
        }
    }
    return true;
}