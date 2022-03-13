#include "Util.h"
using namespace std;

int Util::manhattan_distance(pair<unsigned char, unsigned char> &point1, pair<unsigned char, unsigned char> &point2)
{
    return abs(point1.first - point2.first + point1.second - point2.second);
}

// Converts a matrix into an array.
void Util::convert_to_array(vector<vector<unsigned char>> &inMatrix, vector<unsigned char> &outArray)
{
    int pos = 0;
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            outArray.push_back(inMatrix[row][col]);
        }
    }
}

// Converts a matrix into a string
string Util::MatrixToString(vector<vector<unsigned char>> &inMatrix)
{
    string result = "";
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            result += to_string(inMatrix[row][col]) + ' ';
        }
    }
    return result;
}

void Util::print_path(string &path, int &depth)
{
    int pos = 0;
    for (int curDepth = 0; curDepth <= depth; curDepth++)
    {
        for (int row = 0; row < WIDTH; row++)
        {
            for (int col = 0; col < WIDTH; col++)
            {
                if (isdigit(path[pos]) && isdigit(path[pos + 1]))
                {
                    cout << path[pos] << path[pos + 1] << ' ';
                    pos += 2;
                }
                else if (isdigit(path[pos]))
                {
                    cout << ' ' << path[pos] << ' ';
                    pos++;
                }
                else
                {
                    pos++;
                    col--;
                }
            }
            cout << '\n';
        }
        cout << "============\n";
    }
}

int Util::count_transpositions(Game &initialState, Game &finalState)
{ // isto corre em n^2 (talvez dê para fazer melhor..)
    // a lógica é contar o número de swaps que têm de ser feitos (temos de pensar porque é que isto funciona (se funcionar))
    vector<unsigned char> configuration1(WIDTH * WIDTH);
    vector<unsigned char> configuration2(WIDTH * WIDTH);
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

int Util::CountInversions(Game &game)
{
    vector<unsigned char> arr;
    convert_to_array(game.mat, arr);

    int inversions = 0;
    for (int i = 0; i < WIDTH * WIDTH; i++)
    {
        for (int j = i + 1; j < WIDTH * WIDTH; j++)
        {
            if (arr[i] > arr[j] && arr[j] != 0)
                inversions++;
        }
    }

    return inversions;
}

bool Util::CheckSolvability(Game &initialState, Game &finalState)
{
    int invI = CountInversions(initialState);
    int invF = CountInversions(finalState);

    bool condI = ((invI % 2 == 0) == (initialState.blankPosition.first % 2 == 1));
    bool condF = ((invF % 2 == 0) == (finalState.blankPosition.first % 2 == 1));

    return (condI == condF);
}