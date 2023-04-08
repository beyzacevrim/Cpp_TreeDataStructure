#include <iostream>
using namespace std;

// Define a structure for a node in the AVL tree, which has a key, left and right pointers and a height value
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

// A utility function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// A utility function to get the height of a node in the AVL tree
int height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// A utility function to create a new node with the given key and initialize its left and right pointers to NULL and its height to 1
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// A utility function to perform a right rotation on a node y and return the new root node x
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update the height of the nodes after rotation
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// A utility function to perform a left rotation on a node x and return the new root node y
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update the height of the nodes after rotation
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// A utility function to get the balance factor of a node in the AVL tree
int getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// define a function to insert a node into an AVL tree
Node *insert(Node *node, int key)
{
    // if the tree is empty, create a new node and return it as the root
    if (node == NULL)
        return newNode(key);

    // recursively insert the node in the appropriate sub-tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // check if the node violates the AVL property and perform appropriate rotations if necessary
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// define a function to traverse and print the nodes of the AVL tree in preorder traversal
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    // create an empty AVL tree
    Node *root = NULL;

    // insert nodes into the tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // print the nodes of the AVL tree in preorder traversal
    cout << "Preorder traversal of AVL tree is \n";
    preOrder(root);

    return 0;
}