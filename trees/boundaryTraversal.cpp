#include <bits/stdc++.h>
#include "node.h"

using namespace std;

class Solution {
public:
    void getBoundary(TreeNode* root, bool leftBoundary, bool rightBoundary, vector<int> &left, vector<int> &right, vector<int> &leaf) {
        if(!root)
            return;
        if(!root->left && !root->right) {
            leaf.push_back(root->val);
            return;
        }
        if(leftBoundary) {
            left.push_back(root->val);
            getBoundary(root->left, (root->left != nullptr), rightBoundary, left, right, leaf);
            getBoundary(root->right, (root->left == nullptr), rightBoundary, left, right, leaf);
        }
        else if(rightBoundary) {
            right.push_back(root->val);
            getBoundary(root->left, leftBoundary, (root->right == nullptr), left, right, leaf);
            getBoundary(root->right, leftBoundary, (root->right != nullptr), left, right, leaf);
        }
        else {
            getBoundary(root->left, leftBoundary, rightBoundary, left, right, leaf);
            getBoundary(root->right, leftBoundary, rightBoundary, left, right, leaf);
        }
    }
    vector<int> boundaryTraversal(TreeNode* root) {
        if(!root)
            return {};
        if(!root->left && !root->right)
            return {root->val};
        vector<int> left(0), right(0), leaf(0);
        left.push_back(root->val);
        getBoundary(root->left, true, false, left, right, leaf);
        getBoundary(root->right, false, true, left, right, leaf);
        left.insert(left.end(), leaf.begin(), leaf.end());
        reverse(leaf.begin(), leaf.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

int main() {
    return 0;
}