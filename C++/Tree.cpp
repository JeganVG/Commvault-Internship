#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node* createNode(Node* &node, int val){

    if(node == NULL) return new Node(val);
    if(node->data > val){
        node->left = createNode(node->left, val);
    }
    else{
        node->right = createNode(node->right, val);
    }
    return node;
}

void displayInOrder(Node* &node){
    if(node!=NULL) {
        displayInOrder(node->left);
        cout<<node->data<<"\t";
        displayInOrder(node->right);
    }
}

void displayPreOrder(Node* &node){
    if(node!=NULL){
        cout<<node->data<<"\t";
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }
}

void displayPostOrder(Node* &node){
    if(node!=NULL){
        displayPostOrder(node->left);
        displayPostOrder(node->right);
        cout<<node->data<<"\t";
    }
}

Node* findNode(Node* &node, int val){
    if(node->data == val) return node;
    else if(node->data < val) return findNode(node->left, val);
    else return findNode(node->right, val);
}

Node* findMin(Node* &node){
    while(node->left!=NULL) node=node->left;
    return node;
}

Node* deleteNode(Node* &node, int val){

    if(node == NULL) return NULL;
    if(node->data > val) node->left = deleteNode(node->left, val);
    else if(node->data < val) node->right = deleteNode(node->right, val);
    else {
        Node* temp;
        if(node->left == NULL){
            temp = node->right;
            free(node);
            return temp;
        }
        if(node->right == NULL){
            temp = node->left;
            free(node);
            return temp;
        }
        temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, node->data);
    }
    return node;
}

int main(){
    Node* root = NULL;
    root = createNode(root, 5);
    root = createNode(root, 3);
    root = createNode(root, 8);
    root = createNode(root, 2);
    root = createNode(root, 4);
    root = createNode(root, 6);
    root = createNode(root, 9);

    displayInOrder(root);
    cout<<"\n";
    displayPreOrder(root);
    cout<<"\n";
    displayPostOrder(root);
    cout<<"\n";
    root = deleteNode(root, 3);
    displayInOrder(root);
    return 0;
}