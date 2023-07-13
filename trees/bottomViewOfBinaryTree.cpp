#include <bits/stdc++.h>
#include "node.h"

using namespace std;

vector<int> bottomView(TreeNode* root) {
    if(!root)
        return {};
    if(!root->left and !root->right)
        return {root->val};
    queue<pair<TreeNode*, int>> q;
    map<int, int> nodes;
    q.push({root, 0});
    while(!q.empty()) {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        TreeNode* node = temp.first;
        int x = temp.second;
        nodes[x] = node->val;
        if(node->left)
            q.push({node->left, x - 1});
        if(node->right)
            q.push({node->right, x + 1});
    }
    vector<int> ans(0);
    map<int, int>::iterator itr;
    for(itr = nodes.begin(); itr != nodes.end(); itr++)
        ans.push_back((*itr).second);
    return ans;
}

int main() {
    return 0;
}