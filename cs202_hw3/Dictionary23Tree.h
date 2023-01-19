
#include "DictionaryAVLTree.h"
#include "Node23.h"

class Dictionary23Tree: public DictionarySearchTree{
public:
    Dictionary23Tree( string dictionaryFile );

    ~Dictionary23Tree();
    void deleteSubTree(Node23*& node);

    void insert( string word );

    Node23* insertItem(Node23*& node, string& word,bool& split);

    Node23* split(Node23*& node, string& word);

    void search( string word, int& numComparisons, bool& found ) const;

    int getHeight(Node23*& node);

    void inorderTraverse(Node23*& node);

    void search( string queryFile, string outputFile ) const;

private:
    Node23* root;


};