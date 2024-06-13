#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int height;
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
            height = 0;
        }
};

int heightOfNode(Node* &node){
    if(node == NULL) return -1;
    else return node->height;
}

int findBalanceFactor(Node* &node){
    if(node==NULL) return 0;
    return (node->left->height - node->right->height);
}

int max(int a, int b){
    return a>b?a:b;
}

Node* insert(Node* &node, int val){
    if(node == NULL) return new Node(val);
    else if(val < node->data) node->left = insert(node, val);
    else if(val > node->data) node->right = insert(node, val);
    else return node;

    node->height = 1+ max(node->left->height, node->right->height);

    int balanceFactor = findBalanceFactor(node);

    if(balanceFactor > 1 && val < node->left->data) {
        return rightRotate(node);
    }
    if(balanceFactor > 1 && val > node->right->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);

    }
    if(balanceFactor < 1 && val > node->right->data) {
        return leftRotate(node);

    }
    if(balanceFactor < 1 && val < node->left->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* rightRotate(Node* node){
    Node* y = node->left;
    Node* temp = y->right;

    y->right = node;
    node->left = temp;

    node->height = 1+max(heightOfNode(node->left), heightOfNode(node->right));
    y->height = 1 + max(heightOfNode(y->left), heightOfNode(y->right));

    return y;
}

Node* leftRotate(Node* node){

    Node* y = node->right;
    Node* temp = y->left;

    y->left = node;
    node->right = temp;

    node->height = 1 + max(heightOfNode(node->left), heightOfNode(node->right));
    y->height = 1 + max(heightOfNode(y->left), heightOfNode(y->right));

    return y;

}

int main(){
    Node* root = NULL;
    root = insert(root, 8);

    return 0;
}