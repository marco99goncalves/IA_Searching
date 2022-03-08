#include <bits/stdc++.h>
#include "Game.h"
#include "Util.h"

using namespace std;

// g++ -Wall -o main main.cpp && ./main
Game initial;
Game final;
unordered_set<string> visited;

bool is_visited(string &path)
{
    return !(visited.insert(path).second);
}

// Implementaçao de BFS iterativa
void BFS()
{
    queue<Game *> iterativeQueue;

    iterativeQueue.push(&initial);

    is_visited(initial.path);

    int count = 1;

    while (iterativeQueue.size())
    {
        count++;
        Game *currentGame = iterativeQueue.front();
        iterativeQueue.pop();
        vector<Game *> games;
        currentGame->CreateChildren(games);
        for (Game *child : games)
        {
            string curString = "";
            Util::UpdatePath(child->mat, curString);
            if (curString == final.path)
            {
                cout << "Caminho encontrado\n";
                child->path += final.path;
                Util::print_path(child->path, child->depth);
                cout << "Depth: " << child->depth << '\n';
                cout << "Explored: " << count << " configurations\n";
                return;
            }

            if (!is_visited(curString))
                iterativeQueue.push(child);
        }
    }
}

void DFS()
{
    stack<Game *> iterativeStack;

    iterativeStack.push(&initial);

    is_visited(initial.path);

    int count = 1;
    while (!iterativeStack.empty())
    {
        count++;
        Game *currentGame = iterativeStack.top();
        iterativeStack.pop();

        vector<Game *> games;
        currentGame->CreateChildren(games);

        if (currentGame->depth > 0)
        {
            currentGame->mat.clear();
            delete currentGame;
        }

        for (Game *child : games)
        {
            string curString = "";
            Util::UpdatePath(child->mat, curString);
            if (curString == final.path)
            {
                cout << "Caminho encontrado\n";
                child->path += final.path;
                Util::print_path(child->path, child->depth);
                cout << "Depth: " << child->depth << '\n';
                cout << "Explored: " << count << " configurations\n";
                return;
            }

            if (!is_visited(curString))
                iterativeStack.push(child);
        }
        visited.erase(currentGame->path);
    }
}

int main()
{
    DFS();
    return 0;
}