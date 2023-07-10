#include <iostream>
#include <queue>
#include "node.h"

using namespace std;

vector<vector<int>> bfs(Node* root) {
    vector<vector<int>> ans(0);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level(0);
        for(int i = 0; i < size; i++) {
            Node* temp = q.front();
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