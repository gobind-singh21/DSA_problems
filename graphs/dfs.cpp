#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>> &adjList, int currNode, vector<int> &ans, vector<bool> &visited) {
    visited[currNode] = true;
    ans.push_back(currNode);
    for(int &nodes : adjList[currNode]) {
        if(visited[nodes])
            continue;
        dfs(adjList, nodes, ans, visited);
    }
}

vector<int> dfsIterative(vector<vector<int>> &adjList, int &startNode) {
    int n = adjList.size();
    vector<int> ans(0);
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(startNode);
    while(!st.empty()) {
        int currNode = st.top();
        st.pop();
        if(visited[currNode])
            continue;
        visited[currNode] = true;
        ans.push_back(currNode);
        for(int &node : adjList[currNode])
            st.push(node);
    }
    return ans;
}

int main() {
    return 0;
}