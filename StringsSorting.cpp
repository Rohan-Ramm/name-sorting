#include <iostream>
#include <fstream>
#include <string>
#include "SortingTree.h"
using namespace std;

int main() {
    string filename;
    int scoreRange;
    ifstream infile;
    string fileInput;

    cout << "What is the name of the file? ";
    cin >> filename;
    cout << "The lowest possible score is a 1, what will the highest be? ";
    cin >> scoreRange;

    infile.open(filename);
    if(!infile)
    {
        cout << "File does not exist. " << endl;
        return -1;
    }
    int score = 0;
    infile >> fileInput;
    cout << "What is the score of " << fileInput;
     cin >> score;
    SortingTree<string> *tree = new SortingTree<string>(score,fileInput);
    while(infile >> fileInput) {
        cout << "What is the score of " << fileInput;
        cin >> score;
        if(score > 0 && score <= scoreRange) {
            tree->put(score,fileInput);
        }
    }
    infile.close();
    tree->printTree(cout);
    delete tree;
}