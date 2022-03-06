#pragma once
#include <bits/stdc++.h>
#include "Game.h"
using namespace std;

class Node
{
public:
    Game *game;
    int depth;
    vector<Node *> children;
    Node();
    Node(Game *game, int depth);
    void InsertChild(Node *child);
    void CreateChildren();
    void DFS();
};
