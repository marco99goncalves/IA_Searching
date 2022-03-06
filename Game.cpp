#include <bits/stdc++.h>
#include "Game.h"
using namespace std;

vector<vector<int>> mat(WIDTH, vector<int>(WIDTH));
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
            cout << mat[row][col] << ' ';
        }

        cout << '\n';
    }
    cout << "--\n";
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