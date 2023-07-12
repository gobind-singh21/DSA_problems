#include <iostream>
#include <vector>
#include <stack>
#include "node.h"

using namespace std;

vector<int> inorder(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> ans(0);
    TreeNode* node = root;
    while(true) {
        if(node) {
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty())
                break;
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}

int main() {
    return 0;
}