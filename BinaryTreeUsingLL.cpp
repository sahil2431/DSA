#include<iostream>

using namespace std;

//Creating node class
class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//Preorder Traversal of tree
void preorder(node* root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Postorder Traversal of tree
void postorder(node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//Inorder Travesal of tree
void inorder(node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {

    //creating nodes using class
    node* n1 = new node(2);
    node* n2 = new node(1);
    node* n3 = new node(4);
    node* n4 = new node(11);
    node* n5 = new node(12);
    node* n6 = new node(3);

    //Linking nodes to each other
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n6;

    cout<<"Preorder traversal: ";
    preorder(n1);
    cout<<endl;

    cout<<"Postorder traversal: ";
    postorder(n1);
    cout<<endl;

    cout<<"Inorder traversal: ";
    inorder(n1);
    cout<<endl;

    return 0;
}