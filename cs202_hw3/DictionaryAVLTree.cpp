#include "DictionaryAVLTree.h"

DictionaryAVLTree::DictionaryAVLTree( string dictionaryFile ): DictionarySearchTree(dictionaryFile){

    root = NULL;

    for(int i = 0; i < size ; i++){
        insert(arr[i]);
    }



}

DictionaryAVLTree::~DictionaryAVLTree(){

    deleteSubTree(root);

}

void DictionaryAVLTree::deleteSubTree(TreeNode*& node){

    if(node != NULL){
        deleteSubTree(node->leftChildPtr);
        deleteSubTree(node->rightChildPtr);
    }

    delete node;

}
void DictionaryAVLTree::insert( string word ){

    insertItem(root,word);

}


TreeNode* DictionaryAVLTree::insertItem(TreeNode*& node, const string& word){

    if(node == NULL){
        node = new TreeNode(word,NULL,NULL);
        return node;
    }
    else if(word < node->item){
        insertItem(node->leftChildPtr,word);
    }
    else{
        insertItem(node->rightChildPtr,word);
    }

    handleAVL(node,word);
    return node;

}
void DictionaryAVLTree::handleAVL(TreeNode*& node,string val){

    int differenceInBalance;
    checkBalance(node,differenceInBalance);

    //Insertion is to the left
    if(differenceInBalance > 1 ){

        //LL CASE
        if(val < node->leftChildPtr->item){
            rightRotate(node);
        }

        //LR CASE
        else if(val > node->leftChildPtr->item){
            leftRotate(node->leftChildPtr);
            rightRotate(node);

        }

    }

    //Insertion is to the right
    else if(differenceInBalance < -1){

        //RR CASE
        if(val > node->rightChildPtr->item){
            leftRotate(node);
        }

        //RL CASE
        else if(val < node->rightChildPtr->item){
            rightRotate(node->rightChildPtr);
            leftRotate(node);

        }

    }





}

void DictionaryAVLTree::checkBalance(TreeNode*& node,int&diff){

    int leftHeight = getHeight(node->leftChildPtr);
    int rightHeight = getHeight(node->rightChildPtr);

    diff = leftHeight - rightHeight;

}

int DictionaryAVLTree::getHeight(TreeNode*& node){

    if(node == NULL){
        return 0;
    }

    int treeHeight = getHeight(node->leftChildPtr);
    int rightHeight = getHeight(node->rightChildPtr);

    //choose the side that has greater depth
    if(rightHeight > treeHeight){
        treeHeight = rightHeight;
    }
    return treeHeight+1;

}

void DictionaryAVLTree::leftRotate(TreeNode*& node){

    TreeNode* rightPtr = node->rightChildPtr;
    node->rightChildPtr = rightPtr->leftChildPtr;

    rightPtr->leftChildPtr = node;
    node = rightPtr;

}
void DictionaryAVLTree::rightRotate(TreeNode*& node){

    TreeNode* leftPtr = node->leftChildPtr;
    node->leftChildPtr = leftPtr->rightChildPtr;
    leftPtr->rightChildPtr = node;
    node = leftPtr;

}

void DictionaryAVLTree::search( string word, int& numComparisons, bool& found ) const{



    TreeNode* ptr = root;

    while(ptr != NULL && !found){

        numComparisons++;
        if(word == ptr->item){
            found = true;
        }

        else if(word < ptr->item){
            ptr = ptr->leftChildPtr;
        }

        else{
            ptr = ptr->rightChildPtr;
        }
    }


}

void DictionaryAVLTree::search( string queryFile, string outputFile ) const {

    ifstream qFile;
    qFile.open(queryFile);
    ofstream oFile(outputFile);

    string word;
    int compCount = 0;
    int qCount = 0;
    char isFound = '0';
    bool found = false;
    string out ="";
    int totalComp = 0;
    int maxComp = 0;
    while(qFile >> word){
        search(word,compCount,found);

//        if(!word.empty()){
//            qCount++;
//        }
//
        qCount++;
        if(found){
            isFound = '1';
        }

        out = (word + "  "  +  isFound + "  " + to_string(compCount));
        cout << out << endl;
        oFile << out << endl;

        if(compCount > maxComp){
            maxComp = compCount;
        }

        totalComp = totalComp + compCount;
        isFound = '0';
        found = false;
        compCount = 0;

    }

//# of queries: 8
//    Maximum # of comparisons: 4
//    Average # of comparisons: 3.3750
    oFile << "# of queries: " << qCount << endl;
    oFile << "Maximum # of comparisons: " << maxComp << endl;
    oFile << "Average # of comparisons: " << totalComp / (double)qCount << endl;


}