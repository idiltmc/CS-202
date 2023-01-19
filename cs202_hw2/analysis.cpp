/**
* Title : Binary Search Trees
* Author : İdil Atmaca
* ID: 22002491
* Section : 1
* Assignment : 2
* Description :analyze how the height of BST changes with inserting and deleting random number into/from the tree
*/
#include <iostream>
#include "analysis.h"

using namespace std;



void shuffle(int*& arr,const int size){
    int randIndex;
    for(int i = 0 ; i < size ; i++){
        randIndex = rand() % size; //get a random index within the array
        swap(i,randIndex,arr); //swap random index's item with current index's item
    }
}

void swap(const int index,const int randomIndex, int*& arr){
    int temp = arr[index];
    arr[index] = arr[randomIndex];
    arr[randomIndex] = temp;
}
void heightAnalysis(){

    int size = 30000;
    int breakPoint = 1500; //only print the height with intervals of 1500
    int* arr = new int[size];
    createRandomArray(arr,size); //random array
    cout << endl;
    BST bst;


    cout << "Part f - Analysis of BST height - part 1\n"
            "-----------------------------------------\n"
            "Tree Size Tree Height\n"
            "-----------------------------------------" << endl;


    for(int i = 1 ; i <= size; i++){
        int current = arr[i-1]; //get current item from the array
        bst.insert(current); //insert current item to bst

        //print every 1500 insertions
        if(i % breakPoint == 0){
            cout << i << "                 " << bst.getHeight() << endl;
        }

    }
    cout <<endl;

    shuffle(arr,size); //shuffle the array


    cout << "Part f - Analysis of BST height - part 2\n"
            "-----------------------------------------\n"
            "Tree Size         Tree Height\n"
            "-----------------------------------------" << endl;

    //cout << size<< "         " << bst.getHeight() << endl;
    int *tst = new int[200];
    int j = 0;
    for(int i = 1; i <= size;i++){
        int current = arr[i-1]; //get current item
        bst.deleteKey(current); //delete from bst



        //print every 1500 deletions
        if(i % breakPoint == 0){
            cout << size - i << "                 " << bst.getHeight() << endl;
        }
    }





}

void createRandomArray(int*& arr, const int size){
    for(int i = 0; i < size ;i++){
        int random = rand()% size;
        arr[i] = random;
        //cout << random << " ";
    }
}
