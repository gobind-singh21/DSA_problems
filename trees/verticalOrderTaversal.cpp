#include <bits/stdc++.h>
#include "node.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            int x = temp.second.first, y = temp.second.second;
            TreeNode* node = temp.first;
            nodes[x][y].insert(node->val);
            if(node->left != nullptr)
                q.push({node->left, {x - 1, y + 1}});
            if(node->right != nullptr)
                q.push({node->right, {x + 1, y + 1}});
        }
        vector<vector<int>> ans;
        for(auto itr1 : nodes) {
            vector<int> col;
            for(auto itr2 : itr1.second)
                col.insert(col.end(), itr2.second.begin(), itr2.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};

int main() {
    return 0;
}