#include "DictionarySearchTree.h"

class DictionaryBST: public DictionarySearchTree{
    public:
    DictionaryBST(string dictionaryFile);

    ~DictionaryBST();

    void deleteSubTree(TreeNode*& node);

    void insert( string word );

    void insertItem(TreeNode*& treePtr,const string& word);

    void search( string word, int& numComparisons, bool& found ) const;

    void search( string queryFile, string outputFile ) const;

private:
    TreeNode * root;
};