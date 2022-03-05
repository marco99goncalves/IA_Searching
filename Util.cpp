#include <bits/stdc++.h>
#include "Util.h"
using namespace std;

int Util::manhattan_distance(pair<int, int> &point1, pair<int, int> &point2)
{
    return abs(point1.first - point2.first) + abs(point1.second - point2.second);
}

// Converts a matrix into an array.
void Util::convert_to_array(vector<vector<int>> &inMatrix, vector<int> &outArray)
{
    int pos = 0;
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            outArray[pos++] = inMatrix[row][col];
        }
    }
}

int Util::count_transpositions(Game &initialState, Game &finalState)
{ // isto corre em n^2 (talvez dê para fazer melhor..)
    // a lógica é contar o número de swaps que têm de ser feitos (temos de pensar porque é que isto funciona (se funcionar))
    vector<int> configuration1(WIDTH * WIDTH);
    vector<int> configuration2(WIDTH * WIDTH);
    convert_to_array(initialState.mat, configuration1);
    convert_to_array(finalState.mat, configuration2);

    int transpositions = 0;
    for (int i = 0; i < WIDTH * WIDTH; ++i)
    { // mudar width * width
        if (configuration1[i] == configuration2[i])
            continue;
        for (int j = i; j < WIDTH * WIDTH; ++j)
        {
            if (configuration1[i] != configuration2[j])
                continue;
            swap(configuration2[i], configuration2[j]);
            ++transpositions;
            break;
        }
    }
    return transpositions;
}

bool Util::check_solvability(Game &initialState, Game &finalState)
{
    int manDist = manhattan_distance(initialState.blankPosition, finalState.blankPosition);
    int trans = count_transpositions(initialState, finalState);

    return (manDist + trans) % 2 == 0;
}