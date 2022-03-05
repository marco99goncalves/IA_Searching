#pragma once
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

class Tree
{
public:
    extern Node *root;
    Tree(Node *r);
    void PrintDFS();
};