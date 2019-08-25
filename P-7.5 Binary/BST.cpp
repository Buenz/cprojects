
#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;
#define SPACE 5
BST::BST()
{
    root=NULL;  //make sure root doesn't point to anything
}

BST::node* BST::CreateLeaf(int key){
    node* n=new node;
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    return n; //return pointer to null}
}

void BST::addLeaf(int key){
        addLeafPrivate(key, root);
}
    
void BST::addLeafPrivate(int key, node *ptr){
    if(root==NULL){   ///no nodes made yet
        root=CreateLeaf(key);
    }
    else if(key < ptr->key){//if node is smaller than root
        if(ptr->left!=NULL){
            addLeafPrivate(key, ptr->left);
        }
        else{
            ptr->left=CreateLeaf(key);
        }
    }
    else if(key > ptr->key){
        if(ptr->right!=NULL){
            addLeafPrivate(key, ptr->right);
        }
        else
        {
            ptr->right=CreateLeaf(key);
            
        }
    }
    else
    {
        cout<<" The number has already been added.\n";
    }
    
}
void BST::printTree(){
    ;
    printPrivateTree(root,0);
}

void BST::printPrivateTree(node* ptr, int space){
    if(ptr==NULL){
       for(int i=0;i<space;++i){
            cout<<"\t";}
        cout<<'*'<<endl;
        return;}
    space+=SPACE;
    printPrivateTree(ptr->right, space+1);
    for(int i=SPACE;i<space;i++)
        cout<<"\t";
        cout<<ptr->key<<endl;
        printPrivateTree(ptr->left, space+1);
    }

void BST::printInOrder(){
        printInOrderPrivate(root);
    }

void BST::printInOrderPrivate(node *ptr){
        if(root!=NULL){
            if(ptr->left!=NULL)
            {
                printInOrderPrivate(ptr->left);
            }
            cout<<ptr->key<<" ";
            
            if(ptr->right!=NULL){
                printInOrderPrivate(ptr->right);
            }
        }
        else
        {
            cout<<"The tree is empty.";
        }
    }

