#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> bfs(vector<vector<int>> &adjList, int startNode) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(startNode);
    vector<vector<int>> ans(0);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level(0);
        while(size--) {
            int currNode = q.front();
            q.pop();
            if(visited[currNode])
                continue;
            visited[currNode] = true;
            for(int &node : adjList[currNode])
                q.push(node);
            level.push_back(currNode);
        }
        if(!level.empty())
            ans.push_back(level);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adjList(n, vector<int>(0));
    int startNode = INT_MIN;
    while(n--) {
        int v, u;
        cin >> v >> u;
        if(startNode == INT_MIN)
            startNode = v;
        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }
    vector<vector<int>> ans = bfs(adjList, startNode);
    return 0;
}