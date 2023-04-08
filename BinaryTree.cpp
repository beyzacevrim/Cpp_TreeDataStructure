// This program demonstrates the creation and traversal of a binary tree.

#include <iostream>

using namespace std;

// Define a struct for a node in a binary tree.
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Define a function to create a new node with the given data.
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Define functions for the three types of binary tree traversals.
void inorder(Node *root)
{
    // Inorder traversal visits the left subtree, then the root, then the right subtree.
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node *root)
{
    // Preorder traversal visits the root, then the left subtree, then the right subtree.
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root)
{
    // Postorder traversal visits the left subtree, then the right subtree, then the root.
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Define a function to add a new node with the given data to the binary tree.
void addNode(Node *root, int data)
{
    if (root->left == NULL)
    {
        root->left = newNode(data);
    }
    else if (root->right == NULL)
    {
        root->right = newNode(data);
    }
    else
    {
        // If both the left and right subtrees are full, add the node to the left subtree.
        addNode(root->left, data);
    }
}

int main()
{
    // Create the root node of the binary tree.
    Node *root = newNode(1);

    // Add nodes to the binary tree.
    addNode(root, 2);
    addNode(root, 3);
    addNode(root, 4);
    addNode(root, 5);

    // Print out the binary tree using the three types of traversals.
    cout << "\nInorder traversal of binary tree is: ";
    inorder(root);
    cout << "\nPostorder traversal of binary tree is: ";
    postorder(root);
    cout << "\nPreorder traversal of binary tree is: ";
    preorder(root);

    return 0;
}