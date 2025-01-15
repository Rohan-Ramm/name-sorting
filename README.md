# name-sorting
## Purpose
This program takes lists and sorts them based on user assigned numbers.

## StringsSorting.cpp
This program reads a file of names and then sorts all of them.
It does this by letting the user assign a number to each of them and then sorting them from greatest to least
based on those numbers. It uses a SortingTree data structure to do this.

## Sorting Tree
The Sorting Tree object implements a Binary Search Tree made up of SortingNodes
that contain a generic type and a number. Nodes are sorted based on the number.
SortingTreeDriver.cpp was used to test out the SortingTree.
SortingTree.h is the header file for the object.
SortingTree.cpp implements the methods in the header.
