/*
This is just a test file
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder(Node *node) {
    if(node == NULL) return;

    cout<<node->val<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    Node *node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);

    preOrder(node);
    return 0;
}