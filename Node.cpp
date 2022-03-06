#include <bits/stdc++.h>
#include "Game.h"
#include "Node.h"
using namespace std;

Game *game;
vector<Node *> children(4);
int depth;

Node::Node()
{
    depth = 0;
    Game *g = new Game();
    this->game = g;
}

Node::Node(Game *game, int depth)
{
    this->depth = depth;
    this->game = game;
}

void Node::InsertChild(Node *child)
{
    children.push_back(child);
}

void Node::CreateChildren()
{
    if (depth == 12)
        return;

    vector<Game *> games;
    (*game).CreateChildren(games);

    for (int i = 0; i < games.size(); i++)
    {
        int d = depth + 1;
        Node *n = new Node(games[i], d);
        InsertChild(n);
    }
}

void Node::DFS()
{
    /* cout << depth << '\n';
    (*game).PrintGame(); */
    CreateChildren();
    for (int i = 0; i < children.size(); i++)
    {
        children.at(i)->DFS();
    }
}