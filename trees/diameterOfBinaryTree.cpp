#include <iostream>
#include "node.h"

using namespace std;

int findMax(TreeNode* root, int &maxi) {
    if(!root)
        return 0;
    int left = findMax(root->left, maxi);
    int right = findMax(root->right, maxi);
    maxi = max(maxi, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    findMax(root, ans);
    return ans;
}

int main() {
    return 0;
}