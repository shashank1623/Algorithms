
//Basic Structure of a node in a binary tree
struct Node {
    int data;
    struct Node *left, *right;
};

//Code for Traversal in inOrder and printing
void inOrder(struct Node* node)
{
    if (node == NULL)
        return;    

    inOrder(node->left);

    cout << node->data << " ";

    inOrder(node->right);
}

// We have to call the inOrder Function using the root node like,
// inOrder(root), considering the root of the tree is given to us.