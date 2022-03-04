#include <iostream>
#include "Tree.h"
#include "Node.h"

Node *root;
Tree::Tree(Node *root)
{
    this->root = root;
}

void Tree::PrintDFS()
{
    (*root).DFS();
}