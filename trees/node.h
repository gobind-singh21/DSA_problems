struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x, TreeNode* leftNode, TreeNode* rightNode) {
        val = x;
        left = leftNode;
        right = rightNode;
    }
};