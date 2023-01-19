//#include "DictionarySearchTree.h"
#include "DictionaryBST.h"

class DictionaryAVLTree: public DictionarySearchTree{
public:
    DictionaryAVLTree( string dictionaryFile );

    ~DictionaryAVLTree();

    void deleteSubTree(TreeNode*& node);

    void insert( string word );

    TreeNode* insertItem(TreeNode*& node, const string& word);
    void handleAVL(TreeNode*& node,string val);
    int getHeight(TreeNode*& node);

    void checkBalance(TreeNode*& node,int&diff);


    void leftRotate(TreeNode*& node);
    void rightRotate(TreeNode*& node);

    void search( string word, int& numComparisons, bool& found ) const;

    void search( string queryFile, string outputFile ) const;
private:
        TreeNode* root;


};