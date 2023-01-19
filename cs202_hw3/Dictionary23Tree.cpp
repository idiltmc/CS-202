//
// Created by user on 12/2/2022.
//
#include "Dictionary23Tree.h"
Dictionary23Tree::Dictionary23Tree( string dictionaryFile ): DictionarySearchTree(dictionaryFile){

    root = NULL;
    for(int i = 0; i < size ; i++){
        insert(arr[i]);
    }

    cout << "INORDER" << endl;
    inorderTraverse(root);

    cout << endl;

    cout << "height: " << getHeight(root) <<endl;

}

Dictionary23Tree::~Dictionary23Tree(){
    deleteSubTree(root);

}

void Dictionary23Tree::deleteSubTree(Node23*& node){

    if(node != NULL){
        deleteSubTree(node->leftChildPtr);
        deleteSubTree(node->rightChildPtr);
    }

    delete node;

}

void Dictionary23Tree::insert( string word ){

    bool split = false;
    Node23* ptr;
    ptr = insertItem(root,word,split);

}



int Dictionary23Tree::getHeight(Node23*& node){

    if(node == NULL){
        return 0;
    }

    int treeHeight = getHeight(node->leftChildPtr);
    int rightHeight = getHeight(node->rightChildPtr);
    int middleHeight = getHeight(node->middleChildPtr);

    //choose the side that has greater depth
    if(rightHeight > treeHeight){
        treeHeight = rightHeight;
    }
    if(middleHeight > treeHeight){
        treeHeight = rightHeight;
    }
    return treeHeight+1;

}

Node23* Dictionary23Tree::insertItem(Node23*& node, string& word,bool& isSplitting){

    string emptyS = "";



    //base case, creating a node
    if(node == NULL){
        int itemNum = 1;


        node = new Node23(word,emptyS,itemNum,NULL,NULL,NULL);
        node->itemNum = 1;
        return node;

    }

    //it is a leaf node
    else if( (node->rightChildPtr == NULL && node->middleChildPtr == NULL && node->leftChildPtr == NULL)){

        //there is only 1 item in the node
        if(node->itemNum == 1){

            //update the node according to values
            string smaller = word;
            string larger = node->leftItem;
            if(word >  larger){
                smaller = larger;
                larger = word;
            }



            node->leftItem = smaller;
            node->rightItem = larger;
            node->itemNum = 2;
            return node;

        }

        //node is full, split
        else if(node->itemNum == 2){

            node = split(node,word);
            isSplitting = true;
            return node; //return to the splitted subtree

        }
    }


    //searching for the insertion position
    else{


        Node23* splitNode;

        //traverse to find insertion position
        if(node->itemNum == 1){

            //update the current node after split operation
            //link the current node to the splitted node's children according to their positions

            if(node->leftItem > word){

                splitNode = insertItem(node->leftChildPtr,word,isSplitting);


                if(!isSplitting){
                    return node;
                }

                node->leftChildPtr = splitNode->leftChildPtr;
                node->middleChildPtr = splitNode->rightChildPtr;
            }

            else{


                splitNode =  insertItem(node->rightChildPtr,word,isSplitting);


                if(!isSplitting){
                    return node;
                }
                node->middleChildPtr = splitNode->leftChildPtr;
                node->rightChildPtr = splitNode->rightChildPtr;
            }

            //decide the order in our current 3node
            string smaller = word;
            string larger = node->leftItem;

            if(word > node->leftItem){
                smaller = larger;
                larger = word;
            }


            //updated the node, finished
            node->leftItem = smaller;
            node->rightItem = larger;

            node->itemNum =2;
            isSplitting = false; //we are done


        }
        // overflow,there will be another split
        else if(node->itemNum == 2){
            string small;
            string middle;
            string large;
            Node23* leftSplit;
            Node23* rightSplit;
            Node23* midSplit;

            //according to the base insertion position, split the current node and link correspondingly


            //insertion is in the left subtree
            if(node->leftItem > word){

                //get the split node from the child subtree
                splitNode = insertItem(node->leftChildPtr,word,isSplitting);

                if(!isSplitting){
                    return node;
                }


                small = node->leftItem;
                middle = word;
                large = node->rightItem;


                if(word < small){
                    middle = small;
                    small = word;
                }

                else if(word > large){
                    middle = large;
                    large = word;
                }

                //share the children of the split node and children of the current node in order
                leftSplit = new Node23(small,emptyS,1,splitNode->leftChildPtr,NULL,
                                               splitNode->rightChildPtr);
                rightSplit = new Node23(large,emptyS,1,node->middleChildPtr,NULL,node->rightChildPtr);


            }

            //insertion is in the right subtree
            else if(node->rightItem < word){
                splitNode =  insertItem(node->rightChildPtr,word,isSplitting);

                if(!isSplitting){
                    return node;
                }

                small = node->leftItem;
                middle = word;
                large = node->rightItem;


                if(word < small){
                    middle = small;
                    small = word;
                }

                else if(word > large){
                    middle = large;
                    large = word;
                }

                leftSplit = new Node23(small,emptyS,1,node->leftChildPtr,NULL,
                                       node->middleChildPtr);
                rightSplit = new Node23(large,emptyS,1,splitNode->leftChildPtr,
                                        NULL,splitNode->rightChildPtr);



            }

            //insertion is in the middle subtree
            else{
                splitNode = insertItem(node->middleChildPtr,word,isSplitting);


                if(!isSplitting){
                    return node;
                }

                small = node->leftItem;
                middle = word;
                large = node->rightItem;


                if(word < small){
                    middle = small;
                    small = word;
                }

                else if(word > large){
                    middle = large;
                    large = word;
                }
                leftSplit = new Node23(small,emptyS,1,node->leftChildPtr,NULL,
                                       splitNode->leftChildPtr);

                rightSplit = new Node23(large,emptyS,1,splitNode->rightChildPtr,NULL,node->rightChildPtr);



            }


            //we reached the root, it is 3 node, we have to insert an item
            if( node == root && (node->rightChildPtr != NULL)){


                // create a new root node and we are done
                node = new Node23(word,emptyS,1,leftSplit,NULL,rightSplit);

                isSplitting = false;
                return node;

            }


            //return to split node
                midSplit = new Node23(middle,emptyS,1,leftSplit,NULL,rightSplit);
                return midSplit;





        }



    }
    return node; //just in case


}

//to see the tree clearly
void Dictionary23Tree::inorderTraverse(Node23 *&node) {



    if (node != NULL) {

        inorderTraverse(node->leftChildPtr);
        cout << node->leftItem;
        cout << "  ";

        if(node->itemNum == 2){

            cout << node->rightItem;
            cout << "  ";

            inorderTraverse(node->middleChildPtr);

        }

        inorderTraverse(node->rightChildPtr);
    }
}

//splitting for the leaf nodes
Node23* Dictionary23Tree::split(Node23*& node, string& word){

    string small;
    string middle;
    string large;

    //decide the order of the items in the node

    if(word < node->leftItem){
        small = word;
        middle = node->leftItem;
        large = node->rightItem;
    }

    else if(word > node->leftItem && word < node->rightItem ){

        small = node->leftItem;
        middle = word;
        large = node->rightItem;

    }
    else{
        small = node->leftItem;
        middle = node->rightItem;;
        large = word;

    }

    node->leftItem = small;
    node->rightItem = large;
    int itemNum = 1;
    Node23* lNode;
    Node23* rNode;
    Node23* mNode;


    //create a node from the middle item, left item and right item
    //make left item, child of middle item
    //make right item, child of middle item
    //return to the middle
    //update word, we have to insert the middle item now

    string emptyS = "";
    lNode = new Node23(small,emptyS,itemNum,NULL,NULL,NULL);
    rNode = new Node23(large,emptyS,itemNum,NULL,NULL,NULL);
    mNode = new Node23(middle,emptyS,itemNum,lNode,NULL,rNode);




    word = middle;
    return mNode;

}
void Dictionary23Tree::search( string word, int& numComparisons, bool& found ) const{

    Node23* node = root;

    while (node != NULL && !found){



        numComparisons++;

        if(node->leftItem == word){
            found = true;
        }


        else if( node->itemNum == 2 && node->rightItem == word){
            numComparisons++;
            found = true;

        }

        else{
            if(word < node->leftItem){
                node = node->leftChildPtr;
            }
            else if(node->itemNum == 2 && word > node->leftItem && word < node->rightItem){

                numComparisons++; //we checked it twice for 3node
                node = node->middleChildPtr;
            }
            else{
                node = node->rightChildPtr;
            }

        }


    }


}

void Dictionary23Tree::search( string queryFile, string outputFile ) const{

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

        qCount++;
        if(found){
            isFound = '1';
        }

        out = (word + "  "  ) +  isFound + "  " + to_string(compCount);
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

    oFile << "# of queries: " << qCount << endl;
    oFile << "Maximum # of comparisons: " << maxComp << endl;
    oFile << "Average # of comparisons: " << totalComp / (double)qCount << endl;


}