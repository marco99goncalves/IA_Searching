#pragma once
#include <bits/stdc++.h>
#include "Game.h"
using namespace std;

class Node
{
public:
    Game *game;
    vector<Node> children;
    Node();
    void SetChildren(int index, Node *child);
    void InsertChild(Node *child);
    void DFS();
};
