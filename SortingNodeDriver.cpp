#include <iostream>
#include <string>
#include "SortingNode.h"
using namespace std;

int main() {
    SortingNode<string> node(42, "Alice");
    cout << node.nodeOutput() << endl;

    SortingNode<string> leftChild(23, "Bob");
    node.setLeft(&leftChild);

    if (node.getLeft() != nullptr) {
        cout << "Left child: " << node.getLeft()->nodeOutput() << endl;
    }

    return 0;
}