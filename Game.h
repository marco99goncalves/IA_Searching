#pragma once
#include <bits/stdc++.h>
using namespace std;

class Game
{
public:
    vector<vector<unsigned char>> mat;
    pair<unsigned char, unsigned char> blankPosition;
    string path;
    int depth;

    Game(); // Takes input from the standard input ONLY
    Game(vector<vector<unsigned char>> mat, pair<unsigned char, unsigned char> blankPosition, int depth);
    void PrintGame();
    vector<Game> CreateChildren();
    bool operator==(Game *rhs);
};