#include <bits/stdc++.h>

using namespace std;

// TC : O(E * V), E -> no. of edges, V -> no. of vertices
// SC : O(V)

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for(int i = 0; i < V - 1; i++) {
            for(vector<int> &edge : edges) {
                int src = edge[0], dest = edge[1], wt = edge[2];
                int distance = dist[src] + wt;
                if(distance < dist[dest])
                    dist[dest] = distance;
            }
        }
        
        for(vector<int> &edge : edges) {
            int src = edge[0], dest = edge[1], wt = edge[2];
            int distance = dist[src] + wt;
            if(dist[dest] != 1e8 && distance < dist[dest])
                return {-1};
        }
        
        return dist;
    }
};

int main() {
    return 0;
}