#include <iostream>
#include <string>
#include "SortingNode.h"
using namespace std;

template <typename T>
SortingNode<T>::SortingNode() {
    key = 0;
    value = T();
    left = nullptr;
    right = nullptr;
}

template <typename T>
SortingNode<T>::SortingNode(int newKey, T newValue) {
    key = newKey;
    value = newValue;
    left = nullptr;
    right = nullptr;
}

template <typename T>
SortingNode<T>::SortingNode(int newKey, T newValue, SortingNode *lesser, SortingNode *greater) {
    key = newKey;
    value = newValue;
    left = lesser;
    right = greater;
}

template <typename T>
SortingNode<T>* SortingNode<T>::getLeft() const {
    return left;
}

template <typename T>
SortingNode<T>* SortingNode<T>::getRight() const {
    return right;
}

template <typename T>
void SortingNode<T>::setLeft(SortingNode *newLeft) {
    left = newLeft;
}

template <typename T>
void SortingNode<T>::setRight(SortingNode *newRight) {
    right = newRight;
}

template <typename T>
T SortingNode<T>::getValue() const {
    return value;
}

template <typename T>
void SortingNode<T>::setValue(T newValue) {
    value = newValue;
}

template <typename T>
int SortingNode<T>::getKey() const {
    return key;
}

template <typename T>
string SortingNode<T>::nodeOutput() {
    if constexpr (std::is_same<T, std::string>::value) {
        return "Score of " + value + " is " + to_string(key);
    } else {
        return "Score of " + std::to_string(value) + " is " + to_string(key);
    }
}

