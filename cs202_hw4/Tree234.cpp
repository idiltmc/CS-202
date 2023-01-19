/**
* Title: Tree234
* Author: İdil Atmaca
* ID: 22002491
* Section: 1
* Assignment: 4
* Description: This is 234 tree class which is formed by a red black tree
*/

#include "Tree234.h"




Tree234::Tree234(TreeNode*& tree,string outputFile){

    if(tree!= NULL){


        //initialize root
        int nodeSize = 1;
        int middle;
        int left;
        int right;
        middle = tree->item;

        //always put items to middle first, then fill left and right accordingly
        root =new Node234(0,middle,0,
                          1,0,NULL,NULL,NULL,NULL);

        //if there is a red child, combine them
        if(tree->leftChildPtr != NULL && tree->leftChildPtr->color == 0){
            left = tree->leftChildPtr->item;
            root->leftTaken = true;
            root->leftItem = left; //for 3 nodes, we want to know where out two items are (left middle or middle right)
            nodeSize++;
        }
        if(tree->rightChildPtr != NULL && tree->rightChildPtr->color == 0){
            right = tree->rightChildPtr->item;
            root->rightItem = right;
            nodeSize++;
        }

        root->itemNum = nodeSize;


        initialize(tree,root,0); //insert other items

        printTree(); //testing purposes

        writeFile(outputFile); //write the formed 234 properties to output file


    }


}

//get the string representation of a node
//different algorithms for 4 node, 3 node and 2 node
string Tree234::getPrint(Node234 *&node) {
    string res = to_string(node->ID);
    res = res + "  ";

    if(node->itemNum == 3){

        res = res + to_string(node->leftItem);
        res = res + "  ";

        res = res + to_string(node->middleItem);
        res = res + "  ";

        res = res + to_string(node->rightItem);
        res = res + "  ";

        if(node->leftChildPtr != NULL){
            res = res + to_string(node->leftChildPtr->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }

        if(node->middleL != NULL){
            res = res + to_string(node->middleL->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }

        if(node->middleR != NULL){
            res = res + to_string(node->middleR->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }

        if(node->rightChildPtr != NULL){
            res = res + to_string(node->rightChildPtr->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }

    }

    else if(node->itemNum == 2){

        if(node->leftTaken){
            res = res + to_string(node->leftItem);
            res = res + "  ";

            res = res + to_string(node->middleItem);
            res = res + "  ";

        }
        else{
            res = res + to_string(node->middleItem);
            res = res + "  ";

            res = res + to_string(node->rightItem);
            res = res + "  ";
        }


        if(node->leftChildPtr != NULL){
            res = res + to_string(node->leftChildPtr->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }

        if(node->middleL != NULL){
            res = res + to_string(node->middleL->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }

        if(node->middleR != NULL){
            res = res + to_string(node->middleR->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }

        if(node->rightChildPtr != NULL){
            res = res + to_string(node->rightChildPtr->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }
    }

    else if(node->itemNum == 1){

        //only yhe middle item is filled, put -1 to others
        res = res + to_string(node->middleItem);
        res = res + "  -1   -1  ";


        //if there is left or right child, put their id
        if(node->leftChildPtr != NULL){
            res = res + to_string(node->leftChildPtr->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }

        //middle pointers are NULL, put -1
        res = res + "-1  -1  ";

        if(node->rightChildPtr != NULL){
            res = res + to_string(node->rightChildPtr->ID);
            res = res + "  ";
        }
        else{
            res = res + "-1";
            res = res + "  ";

        }


    }

    return res;
}

//find the node with the given id number
Node234* Tree234::search(Node234* cur,const int index,bool& found) {

    if(cur == NULL){
        return NULL;
    }

    if(cur != NULL) {


        //current node is what we want
        if (cur->ID == index) {
            found = true;
            return cur;
        }

        //left child
        if (cur->leftChildPtr != NULL) {

            if (cur->leftChildPtr->ID == index) {

                found = true;
                return cur->leftChildPtr;
            }

        }
        //middle left child
        if (cur->middleL != NULL) {

            if (cur->middleL->ID == index) {

                found = true;
                return cur->middleL;
            }

        }
        //middle right child
        if (cur->middleR != NULL) {

            if (cur->middleR->ID == index) {

                found = true;
                return cur->middleR;
            }


        }

        //right child
        if (cur->rightChildPtr != NULL) {

            if (cur->rightChildPtr->ID == index) {

                found = true;
                return cur->rightChildPtr;
            }

        }



        found = false;
        //if we could not find it in first two levels, search for each child too
        Node234* temp = NULL;


        if(cur->leftChildPtr != NULL) {



            temp = search(cur->leftChildPtr, index, found);

            if (found) {
                return temp;
            }

        }


        if(cur->middleL != NULL) {


            temp = search(cur->middleL, index, found);
            if (found) {
                return temp;
            }
        }

        if(cur->middleR != NULL) {


            temp = search(cur->middleR, index, found);
            if (found) {
                return temp;
            }
        }

        if(cur->rightChildPtr != NULL) {


            temp = search(cur->rightChildPtr, index, found);
            if (found) {
                return temp;
            }
        }

    }

    return NULL; //just in case








}

//writing the properties to output file
void Tree234::writeFile(string fileName) {



    ofstream oFile(fileName);

    oFile <<  nodeNum +1  << " " << to_string(root->ID) << endl;
    int count = 0;
    Node234* cur;
    bool found = false;
    while(count <= nodeNum){
        cur = search(root,count,found);
        cout << count << "  " << cur->middleItem << endl;
        count++;
        oFile << getPrint(cur) << endl;
    }



}
Tree234::~Tree234(){
    deleteItem(root);

}

void Tree234::deleteItem(Node234 *node) {
    if(node != NULL){
        deleteItem(node->leftChildPtr);
        deleteItem(node->middleL);
        deleteItem(node->middleR);
        deleteItem(node->rightChildPtr);

        delete node;
    }
}



//if there are red children, update the node accordingly
void Tree234::formNode(Node234 *&formingNode, TreeNode *&node) {


    int nodeSize = 1;
    int left;
    int right;

    //left child is red
    if(node->leftChildPtr != NULL && node->leftChildPtr->color == 0){
        left = node->leftChildPtr->item;
        formingNode->leftTaken = true;
        formingNode->leftItem = left;
        nodeSize++;
    }

    //right child is red
    if(node->rightChildPtr != NULL && node->rightChildPtr->color == 0){
        right = node->rightChildPtr->item;
        formingNode->rightItem = right;
        nodeSize++;
    }

    formingNode->itemNum = nodeSize;

}

//form the 234 according to red black tree
void Tree234::initialize(TreeNode *&node, Node234 *&newNode,int id) {

    if(newNode == NULL || node == NULL ){

        //printItem(newNode);
        return;
    }
   else {

        Node234 *left = NULL;
        Node234 *midL = NULL;
        Node234 *midR = NULL;
        Node234 *right = NULL;
        TreeNode *cur;


        //current node is a 4 node
        if (newNode->itemNum == 3) {


            //check red black tree's children to  assign their children to our current 234 node
            if (node->leftChildPtr->leftChildPtr != NULL) {
                nodeNum++;
                left = new Node234(0, node->leftChildPtr->leftChildPtr->item, 0, 1, nodeNum, NULL,
                                   NULL, NULL, NULL);

                cur = node->leftChildPtr->leftChildPtr;
                formNode(left, cur); //new children might not be a 2 node, check its children and update it



            }

            if (node->leftChildPtr->rightChildPtr != NULL) {

                nodeNum++;
                midL = new Node234(0, node->leftChildPtr->rightChildPtr->item, 0, 1,
                                   nodeNum, NULL,
                                   NULL, NULL, NULL);


                cur = node->leftChildPtr->rightChildPtr;
                formNode(midL, cur);

            }

            if (node->rightChildPtr->leftChildPtr != NULL) {


                nodeNum++;
                midR = new Node234(0, node->rightChildPtr->leftChildPtr->item,
                                   0, 1, nodeNum, NULL,
                                   NULL, NULL, NULL);


                cur = node->rightChildPtr->leftChildPtr;
                formNode(midR, cur);

            }
            if (node->rightChildPtr->rightChildPtr != NULL) {

                nodeNum++;
                right = new Node234(0, node->rightChildPtr->rightChildPtr->item,
                                    0, 1, nodeNum, NULL,
                                    NULL, NULL, NULL);

                cur = node->rightChildPtr->rightChildPtr;
                formNode(right, cur);


            }


            //assign updated versions to children
            newNode->leftChildPtr = left;
            newNode->middleL = midL;
            newNode->middleR = midR;
            newNode->rightChildPtr = right;



            //continue
            if (left != NULL) {

                initialize(node->leftChildPtr->leftChildPtr, left, left->ID);

            }

            if (midL != NULL) {
                initialize(node->leftChildPtr->rightChildPtr, midL, midL->ID);

            }

            if (midR != NULL) {
                initialize(node->rightChildPtr->leftChildPtr, midR, midR->ID);
            }

            if (right != NULL) {
                initialize(node->rightChildPtr->rightChildPtr, right, right->ID);
            }


        }

        //current node is 3 node
        else if (newNode->itemNum == 2) {


            if (node->leftChildPtr != NULL && node->leftChildPtr->color == 0) {
                if (node->leftChildPtr->leftChildPtr != NULL) {

                    nodeNum++;
                    left = new Node234(0, node->leftChildPtr->leftChildPtr->item,
                                       0, 1, nodeNum, NULL,
                                       NULL, NULL, NULL);

                    cur = node->leftChildPtr->leftChildPtr;
                    formNode(left, cur);

                }
                if (node->leftChildPtr->rightChildPtr != NULL) {

                    nodeNum++;
                    midL = new Node234(0, node->leftChildPtr->rightChildPtr->item, 0, 1, nodeNum, NULL,
                                       NULL, NULL, NULL);

                    cur = node->leftChildPtr->rightChildPtr;
                    formNode(midL, cur);

                }

                if (node->rightChildPtr != NULL) {
                    nodeNum++;
                    right = new Node234(0, node->rightChildPtr->item,
                                        0, 1, nodeNum, NULL,
                                        NULL, NULL, NULL);

                    cur = node->rightChildPtr;
                    formNode(right, cur);
                }
                newNode->leftChildPtr = left;
                newNode->middleL = midL;
                newNode->rightChildPtr = right;

                if (left != NULL) {

                    initialize(node->leftChildPtr->leftChildPtr, left, left->ID);


                }

                if (midL != NULL) {

                    initialize(node->leftChildPtr->rightChildPtr, midL, midL->ID);

                }

                if (right != NULL) {

                    initialize(node->rightChildPtr, right, right->ID);

                }


            } else if (node->rightChildPtr != NULL && node->rightChildPtr->color == 0) {

                if (node->leftChildPtr != NULL) {
                    nodeNum++;
                    left = new Node234(0, node->leftChildPtr->item,
                                       0, 1, nodeNum, NULL,
                                       NULL, NULL, NULL);
                    cur = node->leftChildPtr;
                    formNode(left, cur);
                }


                if (node->rightChildPtr->leftChildPtr != NULL) {
                    nodeNum++;

                    midL = new Node234(0, node->rightChildPtr->leftChildPtr->item,
                                       0, 1, nodeNum, NULL,
                                       NULL, NULL, NULL);

                    cur = node->rightChildPtr->leftChildPtr;
                    formNode(midL, cur);

                }
                if (node->rightChildPtr->rightChildPtr != NULL) {

                    nodeNum++;

                    right = new Node234(0, node->rightChildPtr->rightChildPtr->item,
                                        0, 1, nodeNum, NULL,
                                        NULL, NULL, NULL);

                    cur = node->rightChildPtr->rightChildPtr;
                    formNode(right, cur);

                }

                newNode->leftChildPtr = left;
                newNode->middleL = midL;
                newNode->rightChildPtr = right;

                if (left != NULL) {

                    initialize(node->leftChildPtr, left, left->ID);


                }

                if (midL != NULL) {

                    initialize(node->rightChildPtr->leftChildPtr, midL, midL->ID);

                }

                if (right != NULL) {

                    initialize(node->rightChildPtr->rightChildPtr, right, right->ID);


                }


            }

        }
            //current node is 2 node
            else {

                if (node->leftChildPtr != NULL) {
                    nodeNum++;
                    left = new Node234(0, node->leftChildPtr->item,
                                       0, 1, nodeNum, NULL,
                                       NULL, NULL, NULL);


                    cur = node->leftChildPtr;
                    formNode(left, cur);
                }

                if (node->rightChildPtr != NULL) {
                    nodeNum++;
                    right = new Node234(0, node->rightChildPtr->item,
                                        0, 1, nodeNum, NULL,
                                        NULL, NULL, NULL);
                    cur = node->rightChildPtr;
                    formNode(right, cur);

                }

                newNode->leftChildPtr = left;
                newNode->rightChildPtr = right;
                if (left != NULL) {

                    initialize(node->leftChildPtr, left, left->ID);

                }


                if (right != NULL) {

                    initialize(node->rightChildPtr, right, right->ID);
                }


            }

    }
}


void Tree234::printTree(){

//    printItem(root);
//    printItem(root->leftChildPtr);
//    printItem(root->middleL);
//    printItem(root->middleR);
//    printItem(root->rightChildPtr);
//
//    Node234* temp = root->leftChildPtr;
//    printItem(temp->leftChildPtr);
//    printItem(temp->middleL);
//    printItem(temp->rightChildPtr);
//
//    temp = root->middleL;
//
//    printItem(temp->leftChildPtr);
//    printItem(temp->rightChildPtr);
//
//    temp = root->rightChildPtr;
//    printItem(temp->leftChildPtr);
//    printItem(temp->middleL);
//    printItem(temp->rightChildPtr);







}
void Tree234::printItem(Node234*& node){


    cout << "Items: " ;

    if(node!= NULL) {
        if (node->itemNum == 3 || node->itemNum == 2) {

            cout << node->leftItem << "  " << node->middleItem << "  " << node->rightItem << "  id:  " << node->ID
                 << " item num: " << node->itemNum << endl;

        }


        if (node->itemNum == 1) {
            cout << node->middleItem << "  " << " id : " << node->ID   << " item num: " << node->itemNum << endl;

        }
    }





}
