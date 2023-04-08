#include <iostream>
using namespace std;
// Define a structure for a node in a binary search tree
struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

// Define a class for a binary search tree
class BST
{
    Node *root; // pointer to the root of the tree
public:
    BST()
    {
        root = NULL;
    }

    // function to insert a key into the tree
    void insert(int key)
    {
        root = insertUtil(root, key);
    }

    // utility function to insert a key into the tree
    Node *insertUtil(Node *node, int key)
    {
        if (node == NULL)
        {
            return new Node(key);
        }

        if (key < node->key)
        {
            node->left = insertUtil(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insertUtil(node->right, key);
        }

        return node;
    }

    // function to perform inorder traversal of the tree
    void inorder()
    {
        inorderUtil(root);
    }

    // utility function to perform inorder traversal of the tree
    void inorderUtil(Node *node)
    {
        if (node != NULL)
        {
            inorderUtil(node->left);
            cout << node->key << " ";
            inorderUtil(node->right);
        }
    }

    // function to search for a key in the tree
    Node *search(int key)
    {
        return searchUtil(root, key);
    }

    // utility function to search for a key in the tree
    Node *searchUtil(Node *node, int key)
    {
        if (node == NULL || node->key == key)
        {
            return node;
        }

        if (key < node->key)
        {
            return searchUtil(node->left, key);
        }
        else
        {
            return searchUtil(node->right, key);
        }
    }
};

int main()
{
    // create an instance of BST
    BST bst;

    // insert some keys into the tree
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // print the inorder traversal of the tree
    cout << "Inorder traversal: ";
    bst.inorder();
    cout << endl;

    // search for a key in the tree
    cout << "Searching for key 60: ";
    if (bst.search(60) != NULL)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // search for a key that is not in the tree
    cout << "Searching for key 100: ";
    if (bst.search(100) != NULL)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}