#include <iostream>
#include <vector>
#include <queue>
#include "node.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> answer(0);
        bool leftToRight = true;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0) {
            int size = q.size(), j = 0;
            vector<int> temp(size);
            while(j < size) {
                TreeNode* tempNode = q.front();
                q.pop();
                if(leftToRight)
                    temp[j] = tempNode->val;
                else
                    temp[size - j - 1] = tempNode->val;
                if(tempNode->left)
                    q.push(tempNode->left);
                if(tempNode->right)
                    q.push(tempNode->right);
                j++;
            }
            answer.push_back(temp);
            leftToRight = !leftToRight;
        }
        return answer;
    }
};

int main() {
    return 0;
}