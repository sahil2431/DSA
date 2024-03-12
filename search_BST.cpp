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

//Searching in BST by recursion
node* searchBST_rec(node* root , int key) {
    if(root == NULL) return NULL;
    if(root->data == key) return root;
    else if(root->data > key) {
        return searchBST_rec(root->left , key);
    }
    else {
        return searchBST_rec(root->right , key);
    }
}

//Searching in BST by iteration
node* searchBST_it(node* root , int key) {
    node* temp = root;
    while(temp != NULL) {
        if(temp->data == key) return root;
        else if(temp->data > key) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    return NULL;
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

    int key = 9;
    
    /* if(searchBST_rec(n1 , key) == NULL) cout<<"Not found";
    else cout<<"Found: "<<key; */

    if(searchBST_it(n1 , key) == NULL) cout<<"Not found";
    else cout<<"Found: "<<key;

    return 0;

}