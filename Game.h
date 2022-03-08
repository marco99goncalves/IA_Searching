#pragma once
#include <bits/stdc++.h>
using namespace std;

class Game
{
public:
    vector<vector<int>> mat;
    pair<int, int> blankPosition;
    string path;
    int depth;

    Game(); // Takes input from the standard input ONLY
    Game(vector<vector<int>> &mat, pair<int, int> &blankPosition, string &path, int depth);
    void PrintGame();
    void CreateChildren(vector<Game *> &outGames);
    bool operator==(Game *rhs);
};