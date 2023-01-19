/**
* Title: 234 tree header file
* Author: İdil Atmaca
* ID: 22002491
* Section: 1
* Assignment: 4
*/

#include "Node234.h"
#include "RedBlackTree.h"


class Tree234 {
public:

    Tree234();
    Tree234(TreeNode*& tree,string outputFile);
    ~Tree234();
    void deleteItem(Node234* node);
    void writeFile(string fileName);
    void printTree();
    void initialize(TreeNode*& node,Node234*& newNode,int id);
    void printItem(Node234*& node);
    void formNode(Node234*& formingNode,TreeNode*& node );
    string getPrint(Node234*& node);
    Node234* search(Node234* cur,const int index,bool& found);



    int nodeNum = 0;
    Node234* root;

};