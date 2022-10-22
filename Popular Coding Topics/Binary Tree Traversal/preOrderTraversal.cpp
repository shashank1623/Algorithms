
//Basic Structure of a node in tree
struct Node {
    int data;
    struct Node *left, *right;
};

//Code for Traversal in PreOrder and printing
void preOrder(struct Node* node)
{
    if (node == NULL)
        return;    
    cout << node->data << " ";

    preOrder(node->left);
    preOrder(node->right);
}

// We have to call the preOrder Function using the root node like,
// preOrder(root), considering the root of the tree is given to us.