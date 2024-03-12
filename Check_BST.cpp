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

void inorder(node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


//Check a given tree is BST or not
bool isBST(node* root) {
    static node* prev = NULL;
    if(root == NULL) return 1;
    else {
        if(!isBST(root->left)) return 0;

        if(prev != NULL && root->data <= prev->data) return 0;

        prev = root;
        return isBST(root->right);
    }
}

int main() {

    //creating nodes using class
    node* n1 = new node(12);
    node* n2 = new node(8);
    node* n3 = new node(14);
    node* n4 = new node(1);
    node* n5 = new node(10);
    node* n6 = new node(30);
    /*        12
            /   \
           8     14
          / \     \
         1   10    30 */
    //Linking nodes to each other
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n6;
    inorder(n1);
    cout<<endl;
    if(isBST(n1)) cout<<"It is BST";
    else cout<<"Not a BST";
    cout<<endl;
    
    return 0;

}