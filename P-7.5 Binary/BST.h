
#ifndef BST_h
#define BST_h

class BST
{
private:
    struct node{
        int key;
        node* left;
        node* right;};
    
    node *root;
    node* CreateLeaf(int key);
    void addLeafPrivate(int key, node* ptr);
    void printInOrderPrivate(node*ptr);
    void printPrivateTree(node* ptr, int space);
public:
    BST();
    void addLeaf(int key);
    void printInOrder();
    void printTree(node* ptr, const int space);
    void printTree();
};


#endif /* BST_h */
