#include <bits/stdc++.h>
#include "Game.h"
#include "Util.h"
using namespace std;

vector<vector<int>> mat(WIDTH, vector<int>(WIDTH));
static vector<pair<int, int>> directions = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};

pair<int, int> blankPosition;
int depth;
string path;

// Creates a new game
Game::Game()
{
    depth = 0;
    path = "";
    mat.resize(WIDTH);
    for (int row = 0; row < WIDTH; row++)
    {
        mat[row].resize(WIDTH);
        for (int col = 0; col < WIDTH; col++)
        {
            cin >> mat[row][col];
            path += to_string(mat[row][col]) + ' ';
            if (mat[row][col] == 0)
                blankPosition = make_pair(row, col);
        }
    }
}

Game::Game(vector<vector<int>> &mat, pair<int, int> &blankPosition, string &path, int depth)
{
    this->mat = mat;
    this->blankPosition = blankPosition;
    this->path = path;
    this->depth = depth;
}

void Game::CreateChildren(vector<Game *> &outGames)
{

    for (auto x : directions)
    {
        if (x.first + blankPosition.first > 3 || x.first + blankPosition.first < 0)
            continue;
        if (x.second + blankPosition.second > 3 || x.second + blankPosition.second < 0)
            continue;

        vector<vector<int>> matTemp = mat;
        swap(matTemp[x.first + blankPosition.first][x.second + blankPosition.second], matTemp[blankPosition.first][blankPosition.second]);

        pair<int, int> newGameBlankPosition = make_pair(x.first + blankPosition.first, x.second + blankPosition.second);
        string newGamePath = path;
        Util::UpdatePath(matTemp, newGamePath);
        outGames.push_back(new Game(matTemp, newGameBlankPosition, newGamePath, depth + 1));
    }
}

void Game::PrintGame()
{
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            if (mat[row][col] < 10)
            {
                cout << ' ' << mat[row][col] << ' ';
            }
            else
            {
                cout << mat[row][col] << ' ';
            }
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