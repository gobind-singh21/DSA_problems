#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &adjMat, int startNode, vector<bool> &visited) {
        stack<int> st;
        st.push(startNode);
        while(!st.empty()) {
            int currNode = st.top();
            st.pop();
            if(visited[currNode])
                continue;
            for(int &node : adjMat[currNode])
                st.push(node);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i])
                continue;
            dfs(isConnected, i, visited);
            ans++;
        }
        return ans;
    }
};

int main() {
    return 0;
}