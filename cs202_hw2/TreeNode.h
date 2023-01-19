
/**
* Title : Binary Search Trees
* Author : İdil Atmaca
* ID: 22002491
* Section : 1
* Assignment : 2
* Description : TreeNode header file
*/

#include <cstdlib>

class TreeNode {            // node in the tree
private:
    TreeNode() {}
    TreeNode(const int& nodeItem,TreeNode *left = NULL,TreeNode *right = NULL)
            :item(nodeItem),leftChildPtr(left),rightChildPtr(right) {}

    int item;       // data portion
    TreeNode *leftChildPtr;  // pointer to left child
    TreeNode *rightChildPtr; // pointer to right child

    friend class BST;
};
