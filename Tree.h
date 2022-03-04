#pragma once
#include <iostream>
#include "Node.h"

class Tree
{
public:
    Node *root;
    Tree(Node *r);
    void PrintDFS();
};