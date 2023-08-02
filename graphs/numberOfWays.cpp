#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> adjList(n);
        for(vector<int> &edge : roads) {
            long long u = edge[0], v = edge[1], time = edge[2];
            adjList[u].push_back({v, time});
            adjList[v].push_back({u, time});
        }
        vector<long long> ways(n, 0);
        vector<long long> dist(n, INT_MAX);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            pair<long long, long long> it = pq.top();
            long long node = it.second, d = it.first;
            pq.pop();
            for(pair<long long, long long> &adj : adjList[node]) {
                long long adjNode = adj.first, wt = adj.second;
                long long distance = d + wt;
                if(distance == dist[adjNode])
                    ways[adjNode] += ways[node];
                else if(distance < dist[adjNode]) {
                    ways[adjNode] = ways[node];
                    dist[adjNode] = distance;
                    pq.push({distance, adjNode});
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

int main() {
    return 0;
}