#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(vector<int> &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>> pq;
        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;
        pq.push({0, 1});
        while(!pq.empty()) {
            int node = pq.top().second, d = pq.top().first;
            pq.pop();
            for(pair<int, int> &it : adj[node]) {
                int adjNode = it.first, wt = it.second;
                int distance = d + wt;
                if(distance < dist[adjNode]) {
                    dist[adjNode] = distance;
                    parent[adjNode] = node;
                    pq.push({distance, adjNode});
                }
            }
        }
        if(dist[n] == INT_MAX)
            return {-1};
        vector<int> path;
        int node = n;
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    return 0;
}