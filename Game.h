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
    void PrintGame();
    bool operator==(Game *rhs);
};