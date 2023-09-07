#include <bits/stdc++.h>
#include "node.h"

using namespace std;

// SC : O(h) , where h -> height of BST
// TC : O(1) (average time complexity)

class BSTIterator {
    stack<TreeNode*> st;
    void pushAllLeft(TreeNode *root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        if(root)
            pushAllLeft(root);
    }
    
    int next() {
        TreeNode *root = st.top();
        int val = root->val;
        st.pop();
        if(root->right)
            pushAllLeft(root->right);
        return val;
    }
    
    bool hasNext() {
        bool hasElement = st.empty();
        return !hasElement;
    }
};

int main() {
    return 0;
}