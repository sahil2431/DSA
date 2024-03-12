#include <iostream>

using namespace std;

// Creating node class
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Searching in BST
node *searchBST(node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left->data == key || root->right->data == key)
        return root;
    else if (root->data > key)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
}

// Inorder Travesal of tree
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Insertion in BST
void insert(node *&root, int key)
{
    node *new_node = new node(key);
    if (root == NULL)
        root = new_node;
    else
    {
        node *ptr = root;
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                cout << "Element is present! Can not be inserted again.\n";
                return;
            }
            else if (ptr->data > key)
            {
                if (ptr->left == NULL)
                {
                    ptr->left = new_node;
                    cout << "Element is inserted!\n";
                    return;
                }
                else
                    ptr = ptr->left;
            }
            else
            {
                if (ptr->right == NULL)
                {
                    ptr->right = new_node;
                    cout << "Element is inserted!\n";
                    return;
                }
                else
                    ptr = ptr->right;
            }
        }
    }
}
// Find the inorder predecessor
node *inorderPredecessor(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// Deletion in BST
node *deletion(node *root, int key)
{
    if (root == NULL)
        return NULL;
    node *ipre;

    // Search the node
    if (key < root->data)
        root->left = deletion(root->left, key);
    else if (key > root->data)
        root->right = deletion(root->right, key);

    // Node is found now delete the node
    else
    {
        /* if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        } */
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        ipre = inorderPredecessor(root);
        root->data = ipre->data;
        root->left = deletion(root->left, ipre->data);
    }
    return root;
}

int main()
{
    /*       5
            / \
           2   8
         /    /  \
        1     7   10
                /  \
               9    15
                     \
                      17 */

    node *root = NULL;
    insert(root, 5);
    insert(root, 9);
    insert(root, 7);
    insert(root, 10);
    insert(root, 2);
    insert(root, 8);
    insert(root, 1);
    insert(root, 15);
    insert(root, 9);
    insert(root, 17);
    inorder(root);
    cout << endl;
    deletion(root,5);
    inorder(root);

    return 0;
}
