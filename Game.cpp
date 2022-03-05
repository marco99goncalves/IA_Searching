#include <bits/stdc++.h>
#include "Game.h"
using namespace std;

vector<vector<int>> mat;
pair<int, int> blankPosition;

// Creates a new game
Game::Game()
{
    mat.resize(WIDTH);
    for (int row = 0; row < WIDTH; row++)
    {
        mat[row].resize(WIDTH);
        for (int col = 0; col < WIDTH; col++)
        {
            cin >> mat[row][col];
            if (mat[row][col] == 0)
                blankPosition = make_pair(row, col);
        }
    }
}

void Game::PrintGame()
{
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            cout << mat[row][col] << " ";
        }

        cout << "\n";
    }
    cout << "--\n";
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