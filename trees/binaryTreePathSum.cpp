#include <iostream>
#include "node.h"

using namespace std;

class Solution {
    int findMax(TreeNode* root, int &maxi) {
        if(!root)
            return 0;
        int left = max(0, findMax(root->left, maxi));
        int right = max(0, findMax(root->right, maxi));
        maxi = max(maxi, left + right + root->val);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        findMax(root, sum);
        return sum;
    }
};

int main() {
    return 0;
}