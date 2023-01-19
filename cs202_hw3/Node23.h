#include <cstdlib>

#include <iostream>
using namespace std;
#include <string>

class Node23 {
public:
    Node23() {}
    Node23(const string& nodeItemL,const string& nodeItemR,int itemNumber,Node23 *left = NULL,
           Node23 *middle = NULL,Node23 *right = NULL)
            :leftItem(nodeItemL),rightItem(nodeItemR),leftChildPtr(left),
            middleChildPtr(middle),rightChildPtr(right),itemNum(itemNumber) {}

    string rightItem;       // data portion
    string leftItem;
    Node23 *leftChildPtr;  // pointer to left child
    Node23 *middleChildPtr;
    Node23 *rightChildPtr; // pointer to right child
    int itemNum;

    //friend class BST;
};
