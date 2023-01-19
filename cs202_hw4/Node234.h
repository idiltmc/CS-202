/**
* Title: Node 234
* Author: İdil Atmaca
* ID: 22002491
* Section: 1
* Assignment: 4
* Description: This file is a node class which will be used for 234 trees
*/
#include <cstdlib>

#include <iostream>
using namespace std;
#include <string>

class Node234 {
public:
    Node234() {};
    Node234(const int& nodeItemL,const int& nodeItemM,const int& nodeItemR,int itemNumber,int nodeId,Node234 *left = NULL,
           Node234 *middleLeft = NULL,Node234 *middleRight = NULL,Node234 *right = NULL)
            :leftItem(nodeItemL),rightItem(nodeItemR),middleItem(nodeItemM),leftChildPtr(left),
             middleL(middleLeft),middleR(middleRight),rightChildPtr(right),itemNum(itemNumber),ID(nodeId) {};

    int rightItem;       // data portion
    int middleItem;
    int leftItem;
    bool leftTaken = false;
    Node234 *leftChildPtr;  // pointer to left child
    Node234 *middleR;
    Node234 *middleL;
    Node234 *rightChildPtr; // pointer to right child
    int itemNum;
    int ID;

};
