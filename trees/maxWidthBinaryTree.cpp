#include <bits/stdc++.h>
#include "node.h"

using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*, unsigned int>> bfsQueue;
        pair<TreeNode*, unsigned> startPair = {root, 0};
        bfsQueue.push(startPair);
        int ans = 0;
        while(!bfsQueue.empty()) {
            int size = bfsQueue.size();
            int levelMin = bfsQueue.front().second;
            int first, last;
            for(int i = 0; i < size; i++) {
                pair<TreeNode*, unsigned int> currPair = bfsQueue.front();
                bfsQueue.pop();
                TreeNode* currNode = currPair.first;
                unsigned int currIndex = currPair.second - levelMin;
                if(i == 0)
                    first = currIndex;
                if(i == size - 1)
                    last = currIndex;
                if(currNode->left) {
                    unsigned int leftNodeIndex = 2*currIndex + 1;
                    bfsQueue.push({currNode->left, leftNodeIndex});
                }
                if(currNode->right) {
                    unsigned int rightNodeIndex = 2*currIndex + 2;
                    bfsQueue.push({currNode->right, rightNodeIndex});
                }
            }
            int width = last - first + 1;
            ans = max(ans, width);
        }
        return ans;
    }
};

int main() {
    return 0;
}