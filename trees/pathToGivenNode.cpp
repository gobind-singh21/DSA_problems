#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

vector<int> pathToNode(TreeNode* root, int B, vector<int> path = {}) {
    if(!root)
        return {};
    path.push_back(root->val);
    if(root->val == B)
        return path;
    vector<int> arr1 = pathToNode(root->left, B, path);
    if(!arr1.empty())
        return arr1;
    vector<int> arr2 = pathToNode(root->right, B, path);
    return arr2;
}

int main() {
    return 0;
}