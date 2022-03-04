#include <iostream>
#include "Game.h"
#include "Node.h"
#include <vector>
#include <iterator>

Game *game;
std::vector<Node *> children;

Node::Node(Game *g)
{
    game = g;
}

Node::Node(std::string game)
{
    Game *g = new Game(game);
    this->game = g;
}

// TODO: Delete this shit
void Node::SetChildren(int index, Node *child)
{
    children.at(index) = (*child);
}

void Node::InsertChild(Node *child)
{
    children.push_back(*child);
    std::cout << &children.back() << "\n";
}

void Node::DFS()
{
    (*game).PrintGame();
    for (int i = 0; i < children.size(); i++)
    {
        children.at(i).DFS();
    }
}