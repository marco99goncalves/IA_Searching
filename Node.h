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
    void InsertChild(Node &child);
    void DFS();
};
