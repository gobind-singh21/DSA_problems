#include <iostream>
#include "node.h"

using namespace std;

class Solution {
public:
    bool checkSymmetric(TreeNode* leftRoot, TreeNode* rightRoot) {
        if(leftRoot == NULL || rightRoot == NULL)
            return leftRoot == rightRoot;
        if(leftRoot->val != rightRoot->val)
            return false;
        return checkSymmetric(leftRoot->left, rightRoot->right) && checkSymmetric(leftRoot->right, rightRoot->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        if(!root->left && !root->right)
            return true;
        return checkSymmetric(root->left, root->right);
    }
};

int main() {
    return 0;
}