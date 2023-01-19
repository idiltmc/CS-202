/**
* Title: main
* Author: İdil Atmaca
* ID: 22002491
* Section: 1
* Assignment: 4
*/
#include <iostream>
#include "Tree234.h"


//takes file directories from arguments
int main(int argc, char** argv)
{

       cout << argv[1] << endl;

      RedBlackTree* rbt = new RedBlackTree(argv[1]); //get the input file and construct red black tree from it

    //get red black tree's root and form a 234 tree,write it into output file
      Tree234* test = new Tree234(rbt->root,argv[2]);




    return 0;
}