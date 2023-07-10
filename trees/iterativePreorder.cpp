#include <iostream>
#include <stack>
#include <vector>
#include "node.h"

using namespace std;

vector<int> preorder(Node* root) {
    if(!root)
        return {};
    vector<int> ans(0);
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* temp = st.top();
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
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    node1->left = node2;
    node1->right = node3;
    node2->right = node4;
    node3->left = node5;
    printVector(preorder(node1));
    return 0;
}