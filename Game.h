#pragma once
#include <bits/stdc++.h>
using namespace std;

#define WIDTH 2

class Game
{
public:
    extern vector<vector<int>> mat;
    extern pair<int, int> blankPosition;
    Game(); // Takes input from the standard input ONLY
    void PrintGame();
    int GetInversionPolarity();
    bool operator==(Game *rhs);
};