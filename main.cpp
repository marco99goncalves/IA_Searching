#include "Game.h"
#include "Util.h"
#pragma GCC optimize("Ofast")

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
int nodeCount = 0;
bool DFS(int DEPTH)
{
    stack<Game> iterativeStack;
    stack<Game> visitedStack;
    unordered_set<string> visited;

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
                nodeCount--;
                visited.erase(visitedStack.top().path);
                visitedStack.pop();
            }
        }

        visited.insert(currentGame.path);
        visitedStack.push(currentGame);

        previousDepth = currentGame.depth;

        vector<Game> games;

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
            nodeCount++;
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
    if (!Util::CheckSolvability(initial, final))
    {
        cout << "Impossivel :( \n";
        return -1;
    }

    DFS(1000000);

    return 0;
}