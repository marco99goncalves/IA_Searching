#pragma once
#include <bits/stdc++.h>
#include "Game.h"

using namespace std;
#define WIDTH 4

namespace Util
{
    // Calculates the manhattan distance between two points
    int manhattan_distance(pair<unsigned char, unsigned char> &point1, pair<unsigned char, unsigned char> &point2);

    // Converts a matrix into an array.
    void convert_to_array(vector<vector<unsigned char>> &inMatrix, vector<unsigned char> &outArray);

    // Checks if an initialState can be transformed into a finalState
    bool check_solvability(Game &initialState, Game &finalState);

    int count_transpositions(Game &initialState, Game &finalState);

    string MatrixToString(vector<vector<unsigned char>> &inMatrix);

    void print_path(string &path, int &depth);

    int CountInversions(Game &game);

    bool CheckSolvability(Game &initialState, Game &finalState);

}