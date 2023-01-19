/**
* Title : Binary Search Trees
* Author : İdil Atmaca
* ID: 22002491
* Section : 1
* Assignment : 2
* Description : main
*/
#include <iostream>
#include "analysis.h"
using namespace std;

int main() {
   // 30, 40, 35,20, 50, 45, 10, 25, 5, 15

    cout << "testing for insertion" << endl;
    BST bst;
    bst.insert(30);
    bst.insert(40);
    bst.insert(35);
    bst.insert(20);
    bst.insert(50);
    bst.insert(45);
    bst.insert(10);
    bst.insert(25);
    bst.insert(5);
    bst.insert(15);

    bst.printTree();

    cout << endl;

    cout << "size: " << bst.getSize() << endl;
    cout << "median test" << endl;

    cout << "MEDIAN: "<< bst.medianOfBST() << endl;
    cout << "height of the tree is: " << bst.getHeight() << endl;


    cout << "range test" << endl;
    bst.rangeSearch(21,70);

    cout << endl;


    cout << "testing for deletion" << endl;
    bst.deleteKey(35);
    bst.deleteKey(40);

//    bst.deleteKey(20);
//    bst.deleteKey(10);
//    bst.deleteKey(15);
//    bst.deleteKey(25);
      bst.deleteKey(30);

    bst.printTree();

    cout << endl;

    cout << "height of the tree is: " << bst.getHeight() << endl;
    cout << "size: " << bst.getSize() << endl;


    cout << "median test" << endl;
    cout << "MEDIAN: "<< bst.medianOfBST() << endl;



    cout << "Height analysis" << endl;
    heightAnalysis();

    return 0;
}
