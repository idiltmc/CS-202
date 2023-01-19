
/**
* Title:
* Author: İdil Atmaca
* ID: 22002491
* Section: 1
* Assignment: 4
*/
#include <iostream>
/**
* Title: red black tree header file
* Author: İdil Atmaca
* ID: 22002491
* Section: 1
* Assignment: 4
*/

#include "TreeNode.h"
#include <fstream>
#include <string>

using namespace std;


class RedBlackTree {
public:


    RedBlackTree( string file );
    ~RedBlackTree();
    void deleteItem(TreeNode* node);
    void insert(TreeNode* node, int item );
    void initialize(TreeNode* node, int*& data, int size,int index);
    int search(int*& data, int item,int size);
    void printTree();
    void printItem(TreeNode* node);


    int numOfItems;

    TreeNode* root;
private:


};