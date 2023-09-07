#include <iostream>
#include "node.h"

using namespace std;

void preorderTraversal(TreeNode* root) {
    if(!root)
        return;
    cout << root->val << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if(!root)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << ' ';
}

void inorderTraversal(TreeNode* root) {
    if(!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << ' ';
    inorderTraversal(root->right);
}

int main() {
    return 0;
}