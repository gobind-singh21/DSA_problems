#include <bits/stdc++.h>
#include "node.h"

using namespace std;

vector<int> postorderTraversal(TreeNode* root) {
    if(!root)
        return {};
    if(!root->left && !root->right)
        return {root->val};
    stack<TreeNode*> st1, st2;
    vector<int> ans(0);
    st1.push(root);
    while(!st1.empty()) {
        TreeNode* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left)
            st1.push(temp->left);
        if(temp->right)
            st1.push(temp->right);
    }
    while(!st2.empty()) {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}

int main() {
    return 0;
}