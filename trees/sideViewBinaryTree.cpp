#include <bits/stdc++.h>
#include "node.h"

using namespace std;

class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {
        if(!root)
            return {};
        if(!root->left && !root->right)
            return {root->val};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int firstVal = 0;
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                if(firstVal == 0)
                    firstVal = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(firstVal);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        if(!root->left && !root->right)
            return {root->val};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int lastVal;
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                lastVal = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(lastVal);
        }
        return ans;
    }
};

int main() {
    return 0;
}