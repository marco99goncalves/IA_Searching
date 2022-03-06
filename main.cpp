#include <bits/stdc++.h>
#include "Game.h"
#include "Node.h"
#include "Tree.h"
#include "Util.h"
using namespace std;
// g++ -Wall -o main main.cpp && ./main

int main()
{
    Node n0;
    Node n1;
    Node n2;
    Tree t(&n0);
    n0.InsertChild(&n1);
    n0.InsertChild(&n2);

    t.PrintDFS();

    return 0;
}