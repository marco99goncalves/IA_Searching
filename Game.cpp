#include "Game.h"
#include "Util.h"
using namespace std;

vector<vector<unsigned char>> mat;
static vector<pair<signed char, signed char>> directions = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};

pair<unsigned char, unsigned char> blankPosition;
int depth;
string path;
static int nodeCount = 0;

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
            scanf("%hhu", &mat[row][col]);
            path += to_string(mat[row][col]) + ' ';
            if (mat[row][col] == 0)
                blankPosition = make_pair(row, col);
        }
    }
}

Game::Game(vector<vector<unsigned char>> mat, pair<unsigned char, unsigned char> blankPosition, int depth)
{
    this->mat = mat;
    this->blankPosition = blankPosition;
    this->path = Util::MatrixToString(mat);
    this->depth = depth;
}

vector<Game> Game::CreateChildren()
{
    vector<Game> games;
    for (auto x : directions)
    {
        if (x.first + blankPosition.first > 3 || x.first + blankPosition.first < 0)
            continue;
        if (x.second + blankPosition.second > 3 || x.second + blankPosition.second < 0)
            continue;

        vector<vector<unsigned char>> matTemp = mat;
        swap(matTemp[x.first + blankPosition.first][x.second + blankPosition.second], matTemp[blankPosition.first][blankPosition.second]);

        pair<int, int> newGameBlankPosition = make_pair(x.first + blankPosition.first, x.second + blankPosition.second);
        Game g = Game(matTemp, newGameBlankPosition, depth + 1);
        games.push_back(g);
    }
    return games;
}

void Game::PrintGame()
{
    for (int row = 0; row < WIDTH; row++)
    {
        for (int col = 0; col < WIDTH; col++)
        {
            if (mat[row][col] < 10)
            {
                cout << ' ' << static_cast<int>(mat[row][col]) << ' ';
            }
            else
            {
                cout << static_cast<int>(mat[row][col]) << ' ';
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