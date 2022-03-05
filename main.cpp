#include <bits/stdc++.h>
#include "Game.h"
#include "Node.h"
#include "Tree.h"
#include "Util.h"
using namespace std;
// g++ -Wall -o main main.cpp && ./main

int main()
{
    Game initial;
    Game final;

    cout << (Util::check_solvability(initial, final) ? "Possivel" : "Impossivel :(") << '\n';

    /* Node n("3 1 2 0");
    Node n0("0 0 0 0");
    Node n1("1 1 1 1");
    Node n2("2 2 2 2");
    Node n3("3 3 3 3");
    Node n4("4 4 4 4");
    Node n5("5 5 5 5");

    Tree t(&n);
    n2.InsertChild(&n1);
    n2.InsertChild(&n0);

    n4.InsertChild(&n5);

    std::cout << "n2: " << &n2 << "\n";
    n.InsertChild(&n2);
    std::cout << "n2: " << &n2 << "\n ";
    n.InsertChild(&n3);
    n.InsertChild(&n4);
    std::cout << "ola: " << n.children.capacity() << "\n";

    t.PrintDFS(); */
    return 0;
}