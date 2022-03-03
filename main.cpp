#include <iostream>
#include <string>
#include <algorithm>

// g++ -Wall -o main main.cpp && ./main
#define WIDTH 4

class Game
{
    int mat[WIDTH][WIDTH];

public:
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
};

int main()
{
    Game game("1 2 3 4 5 6 8 12 13 9 0 7 14 11 10 15");
    game.PrintGame();
    return 0;
}