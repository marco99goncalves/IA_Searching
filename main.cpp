#include <iostream>
#include <string>
#include <algorithm>

// g++ -Wall -o main main.cpp && ./main
#define WIDTH 3

class Game
{
public:
    int mat[WIDTH][WIDTH];

    Game(std::string game)
    {
        int num = 0;
        int bytesConsumedNow = 0, bytesConsumedTotal = 0;

        for (int row = 0; row < WIDTH; row++)
        {
            for (int col = 0; col < WIDTH; col++)
            {
                sscanf(game.c_str() + bytesConsumedTotal, "%d%n", &num, &bytesConsumedNow);
                bytesConsumedTotal += bytesConsumedNow;
                mat[row][col] = num;
            }
        }
    }

    void PrintGame()
    {
        for (int row = 0; row < WIDTH; row++)
        {
            for (int col = 0; col < WIDTH; col++)
            {
                std::cout << mat[row][col] << " ";
            }

            std::cout << "\n";
        }
    }

    // Codigo horrivel, mas é meio irrelevante portanto podemos ignorar por agora.
    // Pior das hipoteses fazemos 2 * WIDTH^2 no programa inteiro.
    int GetInversionPolarity()
    {
        int nums[WIDTH * WIDTH];

        int count = 0;
        for (int row = 0; row < WIDTH; row++)
        {
            for (int col = 0; col < WIDTH; col++)
            {
                nums[count++] = mat[row][col];
            }
        }

        int inversions = 0;
        for (int i = 0; i < WIDTH * WIDTH; i++)
        {
            for (int j = i + 1; j < WIDTH * WIDTH; j++)
            {
                if (nums[j] < nums[i] && nums[j] != 0 && nums[i] != 0)
                    inversions++;
            }
        }

        return inversions % 2;
    }

    // Compares two games to see if theyre equal
    // Passed by reference for efficiency
    bool operator==(Game *rhs)
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
};

int main()
{
    Game startState("3 4 2 5 1 7 6 0 8"); // inv = 7
    Game finalState("1 2 3 8 0 4 7 6 5"); // inv = 7

    // Check for solvability before doing anything else
    if (startState.GetInversionPolarity() != finalState.GetInversionPolarity())
    {
        std::cout << "Impossible. \n";
        return 1;
    }

    return 0;
}