#include <bits/stdc++.h>
#include "Game.h"
#include "Util.h"

using namespace std;

// g++ -Wall -o main main.cpp && ./main
Game initial;
Game final;

void PrintSolution(stack<Game> visitedStack, int nodes)
{
    int size = visitedStack.size();
    int depth = visitedStack.top().depth;
    while (!visitedStack.empty())
    {
        visitedStack.top().PrintGame();
        visitedStack.pop();
    }

    cout << "Caminho Encontrado!\n";
    // Do the thing here
    cout << "Depth: " << depth << '\n';
    // cout << "Explored: " << nodes << '\n';
    return;
}

bool DFS(int DEPTH)
{
    stack<Game> iterativeStack;
    stack<Game> visitedStack;
    unordered_set<string> visited;
    int maxDiff = 0;

    iterativeStack.push(initial);
    visitedStack.push(initial);
    int previousDepth = -1;

    while (!iterativeStack.empty())
    {
        Game currentGame = iterativeStack.top();

        iterativeStack.pop();
        if (currentGame.depth <= previousDepth)
        {
            for (int i = 0; i < previousDepth - currentGame.depth + 1; i++)
            {
                // TODO: Apagar o node
                visited.erase(visitedStack.top().path);
                visitedStack.pop();
            }
        }

        visited.insert(currentGame.path);
        visitedStack.push(currentGame);

        previousDepth = currentGame.depth;

        vector<Game> games;

        cout << "Depth: " << currentGame.depth << "\n";
        cout << "HashSet Size: " << visited.size() << "\n";

        if (currentGame.depth < DEPTH)
            games = currentGame.CreateChildren();
        else
            return false;

        for (Game child : games)
        {
            if (visited.find(child.path) != visited.end())
            {
                continue;
            }

            if (child.path == final.path)
            {
                visited.clear();

                iterativeStack.empty();
                visitedStack.push(child);
                PrintSolution(visitedStack, 3);
                return true;
            }
            iterativeStack.push(child);
        }
    }

    return false;
}
int main()
{
    DFS(1000000);
    // initial.PrintCount();
    // Game g = Game(initial.mat, initial.blankPosition, 1);
    // initial.PrintCount();

    return 0;
}