/*
* Title: Sorting and Algorithm Efficiency
* Author: İdil Atmaca
* ID: 22020491
* Section: 1
* Assignment: 1
*/

#include "sorting.h"
#include <iostream>
#include <chrono>
using namespace std;

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){

    bool sorted = false;

    for (int pass = 1; (pass < size) && !sorted; ++pass) {
        sorted = true;
        for (int index = 0; index < size-pass; ++index) {
            int nextIndex = index + 1;
            compCount++;
            if (arr[index] > arr[nextIndex]) {
                swap(arr[index], arr[nextIndex]);
                moveCount = moveCount + 3;
                sorted = false; // signal exchange
            }
        }
    }



};



void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {

    int first = 0;
    int last = size-1;


    mergesort(arr,first,last,compCount,moveCount);



}

void mergesort(int *arr, int first, int last,int &compCount, int &moveCount ) {

    if (first != last) {


        int mid = (last + first) / 2;    // index of midpoint



        mergesort(arr, first, mid, compCount,moveCount);


        mergesort(arr, mid + 1, last,compCount,moveCount);

        // merge the two halves
        merge(arr, first, mid, last, compCount, moveCount);

    };
}


void merge( int *arr, const int first, const int mid, const int last,int &compCount, int &moveCount){


    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int tempIndex = 0;

    int size = last - first + 1;

    int tempArr[size]; //creating a temporary array

    //compare array elements until one of them is done
    while (first1 <= last1 &&  first2 <= last2){


        //add the small one to the temp array
        if(arr[first1] < arr[first2]){
            tempArr[tempIndex] = arr[first1];
            first1++;
        }
        else{
            tempArr[tempIndex] = arr[first2];
            first2++;

        }
        moveCount++;
        compCount++;
        tempIndex++;
    }

    //finish the first list
    while(first1 <= last1){
        tempArr[tempIndex] = arr[first1];
        first1++;
        tempIndex++;
        moveCount++;

    }

    //finish the second list
    while(first2 <= last2){
        tempArr[tempIndex] = arr[first2];
        first2++;
        tempIndex++;
        moveCount++;

    }

    //update the original array with the changes
    for(int i = 0 ; i < tempIndex; i++){
        arr[first + i] = tempArr[i];
        moveCount++;
    }








};



void quickSort(int *arr, const int size, int &compCount, int &moveCount){

    int first = 0;
    int last = size -1;
    compCount = 0;
    moveCount = 0;


    quicksort(arr, first,last, compCount, moveCount);



};

void quicksort(int *arr, int first, int last, int &compCount, int &moveCount) {

    int pivotIndex = first;


    if (first < last) {



        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);



        // sort regions S1 and S2
        quicksort(arr, first, pivotIndex-1, compCount, moveCount);
        quicksort(arr, pivotIndex+1, last, compCount, moveCount);
    }
}

void partition(int *arr, const int first, const int last,  int& pivotIndex,int &compCount, int &moveCount){


    int pivot = arr[pivotIndex];

    //moveCount++;

    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot


        // move item from unknown to proper region
        if (arr[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount = moveCount + 3; //swap is 3 moves
        }
        compCount++;


        // else belongs to S2
    }
    // place pivot in proper position and mark its location
    swap(arr[first], arr[lastS1]);
    moveCount = moveCount + 3; //swap is 3 moves
    pivotIndex = lastS1;

};

void swap( int& num1, int& num2){

    int temp = num1;
    num1 = num2;
    num2 = temp;


};


void displayArray(const int *arr, const int size){

    cout << " ARRAY: " ;
    for(int i = 0 ; i < size ; i++){
        cout << arr[i];
        cout << " ";
    }

};


void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size){


    for(int i = 0 ; i < size ; i++){
        arr1[i] = rand()% size;
        arr2[i] =arr1[i];
        arr3[i] = arr1[i];
    }
}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){

    //create the first elements of the arrays
    arr1[0] = rand()% size;
    arr2[0] = arr1[0];
    arr3[0] = arr1[0];

    for(int i = 1 ; i < size ; i++){

        int ran = rand()% size;  //random number

        // if the current random number is not bigger than the previous value, increment random number
        if(ran <= arr1[i-1])
            ran = ran + arr1[i-1];

        arr1[i] = ran;

        arr2[i] = ran;

        arr3[i] = ran;
    }

}


void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    //create the first elements of the arrays
    arr1[0] = rand()% size;
    arr2[0] = arr1[0];
    arr3[0] = arr1[0];

    for(int i = 1 ; i < size ; i++){

        int ran = rand() % size;//random number

        // if the current random number is not less than the previous value, decrement random number
        if(ran > arr1[i-1])
            ran = arr1[i-1] - (ran-arr1[i-1]);
        else if (ran == arr1[i-1]){
            ran--;
        }

        arr1[i] = ran;

        arr2[i] = ran;

        arr3[i] = ran;
    }

}

void performanceAnalysis(){
    int const size = 12;
    int arraySizes[12] = {4000, 8000, 12000, 16000, 20000, 24000,
                          28000,32000, 36000, 40000,44000, 48000};


    cout << "PERFORMANCE ANALYSIS FOR RANDOMLY GENERATED ARRAYS" << endl;
    printAnalysisTable(arraySizes,size,0);
    cout << "PERFORMANCE ANALYSIS FOR RANDOMLY GENERATED DESCENDING ARRAYS" << endl;
    printAnalysisTable(arraySizes,size,1);
    cout << "PERFORMANCE ANALYSIS FOR RANDOMLY GENERATED ASCENDING ARRAYS" << endl;
    printAnalysisTable(arraySizes,size,2);




}

void getAnalysis(const int size,int* arr1,int*arr2,int*arr3, long double* result1,long double* result2,long double* result3){

    //time
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;



    int compCount = 0;
    int moveCount = 0;

    startTime = std::chrono::system_clock::now();
    bubbleSort(arr1,size,compCount,moveCount);

    elapsedTime = std::chrono::system_clock::now() - startTime;


    // put the results for the bubble sort algorithm to the array
    result1[0] = elapsedTime.count();

    result1[1] = compCount;
    result1[2] = moveCount;





    compCount = 0;
    moveCount = 0;
    startTime = std::chrono::system_clock::now();
    mergeSort(arr2,size,compCount,moveCount);

    elapsedTime = std::chrono::system_clock::now() - startTime;


    // put the results for the merge sort algorithm to the array
    result2[0] = elapsedTime.count();
    result2[1] = compCount;
    result2[2] = moveCount;




    compCount = 0;
    moveCount = 0;
    startTime = std::chrono::system_clock::now();
    quickSort(arr3,size,compCount,moveCount);
    elapsedTime = std::chrono::system_clock::now() - startTime;



    // put the results for the quick sort algorithm to the array
    result3[0] =  elapsedTime.count();
    result3[1] = compCount;
    result3[2] = moveCount;



}

void printAnalysisTable( int* arraySizes, int const size, int choice){



    //creating 2 dimensional arrays for each algorithms' results
    long double** result1 = new long double*[size];
    long double** result2 = new long double*[size];
    long double** result3 = new long double*[size];



    for(int i = 0; i < size ; i++){


        //second dimension of the array consist 3 elements: elapsed time, compCount and moveCount
        long double* res1 = new long double[3];
        long double* res2 = new long double[3];
        long double* res3 = new long double[3];


        //create arrays with certain sizes using elements in the arraySize
        int *arr1 = new int[arraySizes[i]];
        int *arr2 = new int[arraySizes[i]];
        int *arr3 = new int[arraySizes[i]];


        //generate 3 types of arrays: random,descending,ascending
        if(choice == 0){
            createRandomArrays(arr1,arr2,arr3,arraySizes[i]);
        }
        else if(choice == 1)
            createDescendingArrays(arr1,arr2,arr3,arraySizes[i]);

        else{
            createAscendingArrays(arr1,arr2,arr3,arraySizes[i]);
        }

        //get the analysis of each algorithm
        getAnalysis(arraySizes[i],arr1,arr2,arr3,res1, res2,res3);


        //delete random arrays
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

        //add the results to the array
        result1[i] = res1;
        result2[i] = res2;
        result3[i] = res3;

    }

    //print the results
    cout << "-----------------------------------------" << endl;
    cout << "Algorithm Analysis for Bubble Sort" << endl;
    cout << "Array Size    Elapsed time    compCount    moveCount" << endl;
    printSortAnalysis(result1,arraySizes,size);


    cout << "-----------------------------------------" << endl;
    cout << "Algorithm Analysis for Merge Sort" << endl;
    cout << "Array Size    Elapsed time    compCount    moveCount" << endl;
    printSortAnalysis(result2,arraySizes,size);


    cout << "-----------------------------------------" << endl;
    cout << "Algorithm Analysis for Quick Sort" << endl;
    cout << "Array Size    Elapsed time    compCount    moveCount" << endl;
    printSortAnalysis(result3,arraySizes,size);


    //deleting 2D result arrays
    for(int i = 0; i < size; ++i) {
        delete[] result1[i];
    }

    delete[] result1;

    for(int i = 0; i < size; ++i) {
        delete[] result2[i];
    }

    delete[] result2;

    for(int i = 0; i < size; ++i) {
        delete[] result3[i];
    }

    delete[] result3;




}


void printSortAnalysis(long double** arr, int* arraySizes,int const size){

    for(int i = 0 ; i < size ; i++ ){

        cout << arraySizes[i] << "          " << (double)arr[i][0]  << "         "  << (int)arr[i][1] << "        " <<
             (int)arr[i][2] << endl;
    }


}





