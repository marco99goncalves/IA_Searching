#include <bits/stdc++.h>
#include "Game.h"
#include "Node.h"
using namespace std;

Game *game;
vector<Node *> children;

Node::Node()
{
    Game *g = new Game();
    this->game = g;
}

// TODO: Delete this shit
void Node::SetChildren(int index, Node &child)
{
    children.at(index) = child;
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