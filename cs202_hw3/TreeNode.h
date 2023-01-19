
/**
* Title : Binary Search Trees
* Author : İdil Atmaca
* ID: 22002491
* Section : 1
* Assignment : 2
* Description : TreeNode header file
*/

#include <cstdlib>

#include <iostream>
using namespace std;

class TreeNode {            // node in the tree
public:
    TreeNode() {}
    TreeNode(const string& nodeItem,TreeNode *left = NULL,TreeNode *right = NULL)
            :item(nodeItem),leftChildPtr(left),rightChildPtr(right) {}

    string item;       // data portion
    TreeNode *leftChildPtr;  // pointer to left child
    TreeNode *rightChildPtr; // pointer to right child

    //friend class BST;
};
