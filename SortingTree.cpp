#include <iostream>
#include <string>
#include "SortingTree.h"
using namespace std;

template <typename T>
SortingTree<T>::SortingTree() {
    root =  new SortingNode<string>(0,"");
}

template <typename T>
SortingTree<T>::SortingTree(SortingNode<T> *rootNode) {
    root = rootNode;
}

template <typename T>
SortingTree<T>::SortingTree(int key, T value) {
    root = new SortingNode<T>(key,value);
}

template <typename T>
SortingTree<T>::~SortingTree() {
    destructorHelper(root);
}

template <typename T>
void SortingTree<T>::destructorHelper(SortingNode<T> *head) {
    if (head == nullptr) {
        return;
    }
    if (head->getLeft() !=  nullptr) {
        destructorHelper(head->getLeft());
    }
    if(head->getRight() != nullptr) {
        destructorHelper(head->getRight());
    }
    delete head;
}

template <typename T>
void SortingTree<T>::put(int newKey, T newValue) {
    bool added = false;
    SortingNode<T> *currNode = root;
    SortingNode<T> *prevNode = root;
    while(currNode != nullptr && !added) {
        if(currNode->getKey() == newKey) {
            currNode->setValue(currNode->getValue() + "\n" + newValue);
            added = true;
        } 
        else if(currNode->getKey() > newKey) {
            prevNode = currNode;
            currNode = currNode->getLeft();
        } else{
            prevNode = currNode;
            currNode = currNode->getRight();
        }
    }
    if(!added) {
        SortingNode<T> *temp;
        temp = new SortingNode(newKey,newValue);
        if (prevNode->getKey() > newKey){
            prevNode->setLeft(temp);
        }
        else {
            prevNode->setRight(temp);
        }
    }

}

template <typename T>
void SortingTree<T>::put(const SortingNode<T> &newNode) {
    this->put(newNode.getKey(),newNode.getValue());
}

template <typename T>
T SortingTree<T>::get(int key) const{
    T final = T();
    SortingNode<T> *currNode = root;
    while(currNode != nullptr) {
        if (currNode->getKey() == key) {
            final = currNode->getValue();
            currNode = nullptr;
        } 
        else if (currNode->getKey() > key) {
            currNode = currNode->getLeft();
        }
        else {
            currNode = currNode->getRight();
        }
    }
    return final;
}

template <typename T>
void SortingTree<T>::printTree(ostream &output) {
    output << printTreeHelper(root) << endl;
}

template <typename T>
string SortingTree<T>::printTreeHelper(SortingNode<T> *head) {
    if(head->getRight() == nullptr && head->getLeft() == nullptr) {
        return head->getValue();       
    } else if (head->getRight() != nullptr && head->getLeft() == nullptr) {
        return head->getValue() + "\n" + printTreeHelper(head->getRight());       
    } else if (head->getRight() == nullptr && head->getLeft() != nullptr) {
        return printTreeHelper(head->getLeft()) + "\n" + head->getValue(); 
    } else {
        return printTreeHelper(head->getLeft()) + "\n" + head->getValue() + "\n" + printTreeHelper(head->getRight());
    } 
}