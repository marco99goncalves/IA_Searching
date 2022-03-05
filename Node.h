#pragma once
#include <bits/stdc++.h>
#include "Game.h"
using namespace std;

class Node
{
public:
    extern Game *game;
    Node();
    void InsertChild(Node *child);
    void DFS();
};
