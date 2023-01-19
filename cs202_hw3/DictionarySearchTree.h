

#include <iostream>

#include <fstream>
#include <string>

#include "TreeNode.h"
using namespace std;


class DictionarySearchTree {
public:
//Constructor that constructs the dictionary from the input file
    DictionarySearchTree( string dictionaryFile );
//Destructor
    virtual ~DictionarySearchTree();
//Inserts the given word into the dictionary
    virtual void insert( string word ) = 0;
//Searches the given word in the dictionary, and returns the number
//of comparisons made and whether the word is found or not
    virtual void search( string word, int& numComparisons, bool& found ) const;
//Searches all words in the query file in the dictionary, and
//summarizes the results in the output file
    virtual void search( string queryFile, string outputFile ) const;

    int size = 0;
    int qSize = 0;
    string* arr;
    string* queryArr;
};