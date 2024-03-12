#include <iostream>
#include <algorithm>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// gives the height of node
int getHeight(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

node* leftRotate(node *x)
{ // x is a node from where left rotation has to be done
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height =max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height =max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

node* rightRotate(node *y)
{ // y is a node from where right rotation has to be done
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height =max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height =max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

// Calculation of balance factor of node
int balanceFactor(node *root)
{
    if (root == NULL)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        node *new_node = new node(key);
        return new_node;
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    else
    {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = balanceFactor(root);

    // left left rotation
    if (bf > 1 && key < root->left->data)
    {
        return rightRotate(root);
    }

    // right right rotation
    if (bf < -1 && key > root->right->data)
    {
        return leftRotate(root);
    }

    // left right rotation
    if (bf > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right left rotation
    if (bf < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root = NULL;

    root = insert(root, 12);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 6);

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}