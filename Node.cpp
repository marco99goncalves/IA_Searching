#include <bits/stdc++.h>
#include "Game.h"
#include "Node.h"
using namespace std;

Game *game;
vector<Node *> children;
Node *parent;

Node::Node()
{
    children.resize(WIDTH);
    Game *g = new Game();
    this->game = g;
}

void Node::InsertChild(Node &child)
{
    children.push_back(child);
    cout << &children.back() << "\n";
}

void Node::DFS()
{
    (*game).PrintGame();
    for (int i = 0; i < children.size(); i++)
    {
        children.at(i).DFS();
    }
}