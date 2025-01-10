#include <iostream>
#include <string>
#include "SortingNode.h"
#include "SortingTree.h"
using namespace std;

int main() {
    SortingNode<string> node1(42,"Jim");
    SortingNode<string> node2(25,"John");
    SortingNode<string> node3(44,"James");
    SortingNode<string> node4(2,"Jordan");
    SortingTree<string> tree(&node1);
    tree.put(node2);
    tree.put(node3);
    tree.put(node4);
    cout << tree.get(25) << endl;
    tree.printTree(cout);
}