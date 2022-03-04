#pragma once
#include <iostream>
#include "Game.h"
#include <vector>

class Node
{
public:
    Game *game;
    std::vector<Node> children;
    Node(Game *g);
    Node(std::string game);
    void SetChildren(int index, Node *child);
    void InsertChild(Node *child);
    void DFS();
};
