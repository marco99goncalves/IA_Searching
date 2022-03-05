#pragma once
#include <bits/stdc++.h>
#include "Game.h"

using namespace std;

namespace Util
{
    // Calculates the manhattan distance between two points
    int manhattan_distance(pair<int, int> &point1, pair<int, int> &point2);

    // Converts a matrix into an array.
    void convert_to_array(vector<vector<int>> &inMatrix, vector<int> &outArray);

    // Checks if an initialState can be transformed into a finalState
    bool check_solvability(Game &initialState, Game &finalState);

    int count_transpositions(Game &initialState, Game &finalState);
}