/**
* Title : Binary Search Trees
* Author : İdil Atmaca
* ID: 22002491
* Section : 1
* Assignment : 2
* Description : BST header file
*/
#include "TreeNode.h"
class BST{

public:
    BST();  //constructor
    ~BST();  //destructor

    void insert(int key);
    void insertItem(TreeNode*& treePtr,const int& newItem);
    void deleteItem(TreeNode*& treePtr, int item);
    void deleteNodeItem(TreeNode*& treePtr);
    void processLeftmost(TreeNode *&nodePtr,int& treeItem);
    void inorderPrint(TreeNode *&nodePtr);
    void printTree();
    void deleteKey(int key);
    int getHeight();
    int getSize();
    void inorder(TreeNode *treePtr, int& count);
    int height(TreeNode*& treeNode);
    double medianOfBST();
    double findMedian(TreeNode*& treeNode,int& count, bool isEven, int size,int& med1,int& med2,bool finished);
    void rangeSearch(int a, int b);
    void printInRange(int a,int b, TreeNode*& node);


private:
    TreeNode * root;
};
