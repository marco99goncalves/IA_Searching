#pragma once
#include <bits/stdc++.h>
using namespace std;

#define WIDTH 4

class Game
{
public:
    vector<vector<int>> mat;
    pair<int, int> blankPosition;
    Game(); // Takes input from the standard input ONLY
    Game(vector<vector<int>> &mat, pair<int, int> &blankPosition);
    void PrintGame();
    void CreateChildren(vector<Game *> &outGames);
    bool operator==(Game *rhs);
};