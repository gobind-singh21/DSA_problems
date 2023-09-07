#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> bfs(vector<vector<int>> &adj, vector<bool> &visited, int startNode, int &n) {
    queue<pair<int, int>> q;
    q.push({startNode, 0});
    visited[startNode] = true;
    vector<int> dist(n, 0);
    while(!q.empty()) {
        int node = q.front().first, d = q.front().second;
        q.pop();
        dist[node] = d;
        for(int &adjNode : adj[node]) {
            if(!visited[adjNode]) {
                visited[adjNode] = true;
                q.push({adjNode, d + 1});
            }
        }
    }
    return dist;
}

vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    vector<vector<int>> adjList(n, vector<int>());
    for(vector<int> &edge : edges) {
        int v = edge[0], u = edge[1];
        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }
    vector<bool> visited(n, false);
    vector<int> dist = bfs(adjList, visited, src, n);
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            dist[i] = -1;
    }
    return dist;
}

int main() {
    return 0;
}