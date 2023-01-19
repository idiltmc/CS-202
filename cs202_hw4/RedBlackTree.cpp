/**
* Title: Tree234
* Author: İdil Atmaca
* ID: 22002491
* Section: 1
* Assignment: 4
* Description: This is Red-Black tree class which is formed by an input file
*/

#include "Tree234.h"
#include <iostream>
#include <string>

RedBlackTree::RedBlackTree(string fileName) {


    //read the file
    ifstream file;
    string word;
    file.open(fileName);

    int size = 0;
    int* data = new int[999];


    if(!file.is_open()){
        cout << "COULD NOT OPEN FILE!";
    }

    int index = 0;
    int i = 0;
    int first;


    while(file >> word){


        //first item is the node number
        if(i == 0){
            numOfItems = stoi(word);
            i++;

        }

        //second item is the item hold in the root node
        else if(i == 1){

            first = stoi(word);
            i++;
        }

        //others are data which is put into an array
        else{
            data[index] = stoi(word); //add each number to the array in int format
            index++;
            size++;

        }

    }


    //initialize the root node

    root = new TreeNode(first,NULL,NULL);
    root->color = 1;
    int firstIndex = search(data,first,size);

    initialize(root,data,size,firstIndex);

    printTree();



}

RedBlackTree::~RedBlackTree() {
    deleteItem(root);

}

void RedBlackTree::deleteItem(TreeNode *node) {
    if(node != NULL) {
        deleteItem(node->leftChildPtr);
        deleteItem(node->rightChildPtr);

        delete node;
    }
}

int RedBlackTree::search(int *&data, int item,int size) {

    int index = 0;
    bool found = false;

    while(index < size && !found ){

        if(item == data[index]){
            found = true;
        }
        else {
            index = index + 4;
        }

    }

    if(found){
        return index;
    }

    return -1;




}

void RedBlackTree::printTree() {


    printItem(root);
}

void RedBlackTree::printItem(TreeNode *node) {
    if(node != NULL){

        printItem(node->leftChildPtr);

        string color = "red";

        if(node->color == 1){
            color = "black";
        }


        cout <<  "Item: " << node->item << " Color: " << color << endl;
        printItem(node->rightChildPtr);
    }
}
void RedBlackTree::initialize(TreeNode* node, int*& data, int size,int index){

    int itemIndexL = -1;
    int itemIndexR = -1;
    if(index < size && index != -1){


        //find the position of the left child of current item in the array

        if(data[index + 1] != -1){

            itemIndexL = search(data,data[index+1],size);

            //create a new node for left child
            TreeNode* newNode = new TreeNode(data[itemIndexL],NULL,NULL);
            newNode->color = data[itemIndexL + 3];
            node->leftChildPtr = newNode;





        }



        if(data[index+2] != -1){


            //find the position of the right child of current item in the array
            itemIndexR = search(data,data[index+2],size);

            if(itemIndexR != -1){
                TreeNode* newNode2 = new TreeNode(data[itemIndexR],NULL,NULL);
                node->rightChildPtr = newNode2;
                newNode2->color = data[itemIndexR + 3];
            }





        }



    }


    //if there any left child, repeat the process for that

    if(itemIndexL != -1){

        initialize(node->leftChildPtr,data,size,itemIndexL);

    }

    if(itemIndexR != -1){
        initialize(node->rightChildPtr,data,size,itemIndexR);

    }


}