#include <bits/stdc++.h>
#include "node.h"

using namespace std;

vector<int> getTopView(TreeNode* root) {
    if(!root)
        return {};
    if(!root->left && !root->right)
        return {root->val};
    map<int, int> nodes;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        TreeNode* node = temp.first;
        int x = temp.second;
        if(nodes.find(x) == nodes.end())
            nodes[x] = node->val;
        if(node->left)
            q.push({node->left, x - 1});
        if(node->right)
            q.push({node->right, x + 1});
    }
    vector<int> ans;
    for(auto itr : nodes)
        ans.push_back(itr.second);
    return ans;
}

int main() {
    return 0;
}