/**
* Title : Binary Search Trees
* Author : İdil Atmaca
* ID: 22002491
* Section : 1
* Assignment : 2
* Description : pointer-based implementation of Binary Search Tree
*/
#include "BST.h"
#include <iostream>
using namespace std;

BST::BST(){
    root = NULL;
}

BST::~BST(){

}

void BST::insertItem(TreeNode *&treePtr, const int &newItem) {

    //insert
    if(treePtr == NULL){
        treePtr = new TreeNode(newItem,NULL,NULL);
    }

    //go left if the key is small
    else if(newItem < treePtr->item){
        insertItem(treePtr->leftChildPtr,newItem);
    }

    //go right if the key is large
    else{
        insertItem(treePtr->rightChildPtr,newItem);
    }

}
void BST::insert(int key){

    insertItem(root,key);

}

void BST::deleteKey(int key){

    deleteItem(root,key);

}

void BST::deleteItem(TreeNode *&treePtr, int item) {

    if (treePtr == NULL) // Empty tree
        cout << "Delete failed" << endl;

    //deletion item is found
    else if(treePtr->item == item){
        deleteNodeItem(treePtr);
    }


    else if(item < treePtr->item){
        deleteItem(treePtr->leftChildPtr,item);
    }

    else{
        deleteItem(treePtr->rightChildPtr,item);
    }

}

void BST::deleteNodeItem(TreeNode *&treePtr) {


    TreeNode* del;

    //its a leaf node
    if(treePtr->rightChildPtr == NULL && treePtr->leftChildPtr == NULL){
        delete treePtr;
        treePtr = NULL;
    }

    //there is no left child
    else if(treePtr->leftChildPtr == NULL){
        del = treePtr;
        treePtr = treePtr->rightChildPtr;
        del->rightChildPtr = NULL;
        delete del;
    }

    //there is no right child
    else if(treePtr->rightChildPtr == NULL){
        del = treePtr;
        treePtr = treePtr->leftChildPtr;
        del->leftChildPtr = NULL;
        delete del;
    }
    //there are two children
    else{
        int leftMost;
        processLeftmost(treePtr->rightChildPtr,leftMost);
        treePtr->item = leftMost;


    }

}

void BST::printTree() {
    inorderPrint(root);
}
void BST::inorderPrint(TreeNode *&nodePtr) {
    if (nodePtr != NULL) {

        inorderPrint(nodePtr->leftChildPtr);
        cout << nodePtr->item;
        cout << "  ";
        inorderPrint(nodePtr->rightChildPtr);
    }

}
void BST::processLeftmost(TreeNode *&nodePtr, int &treeItem) {
    if(nodePtr->leftChildPtr == NULL){
        treeItem = nodePtr->item;
        TreeNode* del = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        del->rightChildPtr = NULL;
        delete del;
    }
    else{
        processLeftmost(nodePtr->leftChildPtr,treeItem);
    }
}
int BST::getHeight(){
    return height(root);
}

int BST::height(TreeNode *&treeNode) {

    //base case
    if(treeNode == NULL){
        return 0;
    }

    int treeHeight = height(treeNode->leftChildPtr);
    int rightHeight = height(treeNode->rightChildPtr);

    //choose the side that has greater depth
    if(rightHeight > treeHeight){
        treeHeight = rightHeight;
    }
    return treeHeight + 1;


}
int BST::getSize() {
    TreeNode*& node = root;
    int count = 0;

    inorder(root,count);
    return count;
}

double BST::medianOfBST() {
    int size = getSize();  //find the number of items in the tree -> 0(n)

    int count = 0 ;
    int med1;
    int med2;

    //determine if there is even number of items or odd number of items in the tree
    bool isEven = true;

    if(size % 2 == 1){
        isEven = false;
    }

    return findMedian(root,count,isEven,size,med1,med2,false); //find the median -> O(n)

    //time complexity = O(2n) = O(n) linear time
}
void BST::inorder(TreeNode *treePtr, int &count) {

    //inorder traversal
    if(treePtr != NULL){
        inorder(treePtr->leftChildPtr,count);
        count++;
        inorder(treePtr->rightChildPtr,count);
    }

}
double BST::findMedian(TreeNode *&treeNode, int &count, bool isEven, int size,int& med1,int& med2,bool finished) {

    //continue until the median is found -> base case
    if(treeNode != NULL && !finished){

        //if the size is even : median = (med1 + med2) / 2
        //where med1 = (n/2)th node, med2 =  ((n/2) + 1)th node
        if(isEven){

            //inorder traversal
            findMedian(treeNode->leftChildPtr,count,isEven,size,med1,med2,finished);
            count++; //update count

            //med1 is found
            if(count == (size/2)){
                med1 = treeNode->item;
            }
            //med2 is found -> exit
            if(count== size/ 2 + 1){
                med2 = treeNode->item;
                finished = true;
            }
            findMedian(treeNode->rightChildPtr,count,isEven,size,med1,med2,finished);

        }

        //if the size is odd : median = (med1 + med2) / 2
        //where med2 = med1 = (n/2)th node -> middle node
        else{

            //inorder traversal
            findMedian(treeNode->leftChildPtr,count,isEven,size,med1,med2,finished);

            count++;

            //middle node is found -> exit
            if(count == (size / 2) + 1){
                med1 = treeNode->item;
                med2 = treeNode->item;
                finished = true;
            }

            findMedian(treeNode->rightChildPtr,count,isEven,size,med1,med2,finished);
        }

    }

    //calculate the median and return the value
    double median = ((double)med1 + med2) / 2;
    return median;
}

void BST::rangeSearch(int a, int b) {
    TreeNode*& node = root;
    printInRange(a,b,node);
}

void BST::printInRange(int a, int b, TreeNode *&node) {

    //inorder traversal

    //base case -> node = NULL
    if(node != NULL){

        //if current item is more than lower value, search for low values until  lower boundary is reached
        if(node->item >= a){
            printInRange(a,b,node->leftChildPtr);
        }

        //print the item if it is in the range
        if(node->item >= a && node->item <= b){
            cout << node->item << " ";
        }

        //if current item is less than upper value, search for high values until upper boundary is reached
        if(node->item <= b){
            printInRange(a,b,node->rightChildPtr);
        }
    }


}