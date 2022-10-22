
//Basic Structure of a node in tree
struct Node {
    int data;
    struct Node *left, *right;
};

//Code for Traversal in postOrder and printing
void postOrder(struct Node* node)
{
    if (node == NULL)
        return;    

    postOrder(node->left);
    postOrder(node->right);

    cout << node->data << " ";
}

// We have to call the postOrder Function using the root node like,
// postOrder(root), considering the root of the tree is given to us.