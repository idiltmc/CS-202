
/**
* Title: Tree Node
* Author: İdil Atmaca
* ID: 22002491
* Section: 1
* Assignment: 4
* Description: This is a node class which will be used for Red Black trees
*/

#include <cstdlib>

#include <iostream>
using namespace std;

class TreeNode {            // node in the tree
public:
    TreeNode() {}
    TreeNode(const int& nodeItem,TreeNode *left = NULL,TreeNode *right = NULL)
            :item(nodeItem),leftChildPtr(left),rightChildPtr(right) {}

    int item;       // data portion
    int color; // 0 for red, 1 for black
    TreeNode *leftChildPtr;  // pointer to left child
    TreeNode *rightChildPtr; // pointer to right child

    //friend class BST;
};
