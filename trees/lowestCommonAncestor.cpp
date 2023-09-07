#include <iostream>
#include "node.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;
        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
        if(leftNode == NULL)
            return rightNode;
        else if(rightNode == NULL)
            return leftNode;
        else
            return root;
    }
};

int main() {
    return 0;
}