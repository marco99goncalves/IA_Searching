#include <bits/stdc++.h>
#include "Game.h"
#include "Node.h"
using namespace std;

Game *game;
vector<Node *> children(4);
int depth;

Node::Node()
{
    Game *g = new Game();
    this->game = g;
}

void Node::InsertChild(Node *child)
{
    children.push_back(child);
}

void Node::DFS()
{
    (*game).PrintGame();
    for (int i = 0; i < children.size(); i++)
    {
        children.at(i)->DFS();
    }
}