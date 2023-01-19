#include "DictionaryBST.h"


DictionaryBST::DictionaryBST(string dictionaryFile): DictionarySearchTree(dictionaryFile){
    root = NULL;
//    ifstream file;
//    string word;
//
//    file.open(dictionaryFile);
//
//    if(!file.is_open()){
//        cout << "acamadım";
//    }
//
//
//    while(file >> word){
//        insert(word);
//    }

    for(int i = 0; i < size ; i++){
        insert(arr[i]);
    }

}

DictionaryBST::~DictionaryBST(){
    deleteSubTree(root);

}
void DictionaryBST::deleteSubTree(TreeNode*& node){

    if(node != NULL){
        deleteSubTree(node->leftChildPtr);
        deleteSubTree(node->rightChildPtr);
    }

    delete node;

}
void DictionaryBST::insertItem(TreeNode*& treePtr,const string& word){
    if(treePtr == NULL){
        treePtr =  new TreeNode(word,NULL,NULL);
    }

    else if(word < treePtr->item){
        insertItem(treePtr->leftChildPtr,word);
    }
    else{
        insertItem(treePtr->rightChildPtr,word);
    }

}
void DictionaryBST::insert( string word ){

   // TreeNode* newItem = new TreeNode(word,NULL,NULL);
    insertItem(root,word);

}

void DictionaryBST::search( string word, int& numComparisons, bool& found ) const{

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

void DictionaryBST::search( string queryFile, string outputFile ) const{

    //DictionarySearchTree.search(queryFile,outputFile);

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
    while(qFile>> word){
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