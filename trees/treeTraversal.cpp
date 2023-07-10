#include <iostream>
#include "node.h"

using namespace std;

void preorderTraversal(Node* root) {
    if(!root)
        return;
    cout << root->val << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if(!root)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << ' ';
}

void inorderTraversal(Node* root) {
    if(!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << ' ';
    inorderTraversal(root->right);
}

int main() {
    return 0;
}