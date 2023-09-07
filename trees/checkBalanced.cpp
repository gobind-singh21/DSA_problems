#include <iostream>
#include "node.h"

using namespace std;

int check(TreeNode* root) {
    if(!root)
        return 0;
    int left = check(root->left);
    if(left == -1)
        return -1;
    int right = check(root->right);
    if(right == -1 || abs(left - right) > 1)
        return -1;
    return 1 + max(left, right);
}

int main() {
    return 0;
}