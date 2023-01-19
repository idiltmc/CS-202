//
// Created by user on 12/2/2022.
//
#include "DictionarySearchTree.h"

DictionarySearchTree::DictionarySearchTree( string dictionaryFile ){

    //fetch words from the file and add them to the dictionary
    ifstream file;
    string word;
    file.open(dictionaryFile);

    arr = new string[999];
    queryArr = new string[999];


    if(!file.is_open()){
        cout << "COULD NOT OPEN FILE!";
    }


    int index = 0;

    while(file >> word){


        this->arr[index] = word;
        index++;
        size++;

    }

}
//Destructor
DictionarySearchTree::~DictionarySearchTree(){

}
//Inserts the given word into the dictionary
void DictionarySearchTree::insert( string word ){

}
//Searches the given word in the dictionary, and returns the number
//of comparisons made and whether the word is found or not
void DictionarySearchTree::search( string word, int& numComparisons, bool& found ) const{

};
//Searches all words in the query file in the dictionary, and
//summarizes the results in the output file
void DictionarySearchTree::search( string queryFile, string outputFile ) const{

    //ifstream qFile;
//    qFile.open(queryFile);
//    ofstream oFile(outputFile);
//
//    string word;
//    int qCount;
//    string out;
//    int index = 0;
//    while(qFile >> word){
//
//        queryArr[index] = word;
//        qCount++;
//
//
//    }
//
//
//    cout << out << endl;


};