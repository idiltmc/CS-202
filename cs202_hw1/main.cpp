/*
* Title: Sorting and Algorithm Efficiency
* Author: İdil Atmaca
* ID: 22020491
* Section: 1
* Assignment: 1
*/
#include <iostream>
using namespace std;
#include <cmath>
#include "sorting.h"
int main(){


    int const arrSize = 16;


    int testArray1[arrSize] = {40, 25, 29, 56, 37, 27, 24, 32, 79,
                               12, 35, 38, 23, 31,33, 26};
    int testArray2[arrSize] = {40, 25, 29, 56, 37, 27, 24, 32, 79,
                               12, 35, 38, 23, 31,33, 26};
    int testArray3[arrSize] = {40, 25, 29, 56, 37, 27, 24, 32, 79,
                               12, 35, 38, 23, 31,33, 26};




    cout << "Testing for the ";
    displayArray(testArray1,arrSize);
    cout << endl;

    //TESTING BUBBLE SORT
    cout << "Testing bubble sort algorithm" << endl;
    int compCount = 0;
    int moveCount = 0;


    bubbleSort(testArray1,arrSize,compCount,moveCount);
    cout << "Sorted" ;
    displayArray(testArray1,arrSize);
    cout << endl;
    cout << "comparison count: " << compCount << endl;
    cout << "move count: " << moveCount << endl;




    //TESTING MERGE SORT
    cout << endl;
    cout << "Testing merge sort algorithm" << endl;

    compCount = 0;
    moveCount = 0;
    mergeSort(testArray2,arrSize,compCount,moveCount);
    cout << "Sorted" ;
    displayArray(testArray2,arrSize);
    cout << endl;
    cout << "comparison count: " << compCount << endl;
    cout << "move count: " << moveCount << endl;


    //TESTING QUICK SORT
    cout << endl;
    cout << "Testing quick sort algorithm" << endl;


    compCount = 0;
    moveCount = 0;
    quickSort(testArray3,arrSize,compCount,moveCount);
    cout << "Sorted" ;
    displayArray(testArray3,arrSize);
    cout << endl;
    cout << "comparison count: " << compCount << endl;
    cout << "move count: " << moveCount << endl;


    performanceAnalysis();

    return 0;
}

