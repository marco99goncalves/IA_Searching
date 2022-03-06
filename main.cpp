#include <bits/stdc++.h>
#include "Game.h"
#include "Node.h"
#include "Tree.h"
#include "Util.h"
using namespace std;
// g++ -Wall -o main main.cpp && ./main

int main()
{
    Game initialState;
    Game finalState;
    if (!Util::check_solvability(initialState, finalState))
        return -1;

    Node root(&initialState, 0);
    Tree tree(&root);
    tree.PrintDFS();

    return 0;
}