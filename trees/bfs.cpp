#include <iostream>
#include <queue>
#include "node.h"

using namespace std;

vector<vector<int>> bfs(TreeNode* root) {
    vector<vector<int>> ans(0);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level(0);
        for(int i = 0; i < size; i++) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            level.push_back(temp->val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main() {
    return 0;
}