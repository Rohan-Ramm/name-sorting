#include <iostream>
using namespace std;

#ifndef SortingNode_H
#define SortingNode_H

template <typename T>
class SortingNode {
    public:
        SortingNode();
        SortingNode(int newKey, T newValue);
        SortingNode(int newKey, T newValue, SortingNode *lesser, SortingNode *greater);
        SortingNode* getLeft() const; 
        SortingNode* getRight() const;
        void setLeft(SortingNode *newLeft);
        void setRight(SortingNode *newRight);
        void setValue(T newValue);
        T getValue() const;
        int getKey() const;
        string nodeOutput();
    private:
        int key;
        T value;
        SortingNode *left;
        SortingNode *right;
};

#include "SortingNode.cpp"

#endif