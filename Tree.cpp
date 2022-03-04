#include <bits/stdc++.h>
#include "Tree.h"
#include "Node.h"
using namespace std;

Node *root;
Tree::Tree(Node *root)
{
    this->root = root;
}

void Tree::PrintDFS()
{
    (*root).DFS();
}