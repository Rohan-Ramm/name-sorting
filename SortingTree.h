#include <iostream> 
#include <string>
#include "SortingNode.h"
using namespace std;

#ifndef SortingTree_H
#define SortingTree_H

template <typename T>
class SortingTree{
    public:
        SortingTree();
        SortingTree(SortingNode<T> *rootNode);
        SortingTree(int key, T value);
        ~SortingTree();
        void put(int newKey, T newValue);
        void put(const SortingNode<T> &newNode);
        T get(int key) const;
        void printTree(ostream &output);
    private:
        void destructorHelper(SortingNode<T> *head);
        string printTreeHelper(SortingNode<T> *head);
        SortingNode<T> *root;
};
#include "SortingTree.cpp"
#endif