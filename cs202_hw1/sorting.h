/*
* Title: Sorting and Algorithm Efficiency
* Author: İdil Atmaca
* ID: 22020491
* Section: 1
* Assignment: 1
*/

#include <iostream>
using namespace std;

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);


void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void mergesort(int *arr, int first, int last,int &compCount, int &moveCount );
void merge( int *arr, const int first, const int mid, const int last,int &compCount, int &moveCount);

void quicksort(int *arr, int first, int last, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void partition(int *arr, const int first, const int last,  int& pivotIndex,int &compCount, int &moveCount);
void swap( int& a, int& b);
void choosePivot(int *arr, const int first, const int last);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);

void performanceAnalysis();
void getAnalysis(const int size,int* arr1,int*arr2,int*arr3, long double* result1,long double* result2,long double* result3);
void printAnalysisTable( int* arrSizes, int const size,int choice);
void printSortAnalysis(long double** arr, int* arraySizes,int const size);



