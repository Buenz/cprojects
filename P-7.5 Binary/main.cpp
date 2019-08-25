//
//  main.cpp
//  P-7.5 Binary
//
//  Created by Harrison  Bueno on 7/15/18.
//  Copyright © 2018 Harrison  Bueno. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "BST.cpp"

using namespace std;
int main() {
    int treeKeys[16] = {14, 5, 45, 7, 69, 38, 58, 3, 1, 9, 99,12, 13, 44, 15,23};
    BST myTree;
    ///cout<<"\nPrinting tree in order b/f adding numbers: \n";
    //myTree.printInOrder();
    
    for(int i=0; i<16; i++){
        myTree.addLeaf(treeKeys[i]);
    }
   // cout<<"\nPrinting tree in order after adding numbers: \n";
   // myTree.printInOrder();
    
    cout << "\nPrint tree: \n";
    myTree.printTree();
    
     return 0;
}
