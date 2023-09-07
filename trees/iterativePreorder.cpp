#include <iostream>
#include <stack>
#include <vector>
#include "node.h"

using namespace std;

vector<int> preorder(TreeNode* root) {
    if(!root)
        return {};
    vector<int> ans(0);
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* temp = st.top();
        ans.push_back(temp->val);
        st.pop();
        if(temp->right)
            st.push(temp->right);
        if(temp->left)
            st.push(temp->left);
    }
    return ans;
}

void printVector(vector<int> arr) {
    for(int i : arr)
        cout << i << ' ';
    cout << endl;
}

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node2->right = node4;
    node3->left = node5;
    printVector(preorder(node1));
    return 0;
}