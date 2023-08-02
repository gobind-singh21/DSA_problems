#include <bits/stdc++.h>

using namespace std;

// worst case even for dense graph 
// O(V * (pop vertex from min-heap + no. of edges on each vertex(ne)*push into PQ))
// O(V * (log(heap size) + ne * log(heap size)))
// O(V * (ne + 1)* log(heap size))
// ne = V - 1(for worst case i.e dense graph)
// O(V * V * log(heap size))
// heap size for worst case(dense graph) = V^2
// O(V^2 * log(V^2))
// O(2 * V^2 * log(V))
// for dense graph V^2 = E(no. of edges)
// O(E * log V)
// TC : E log V
// E : number of edges
// V : number of nodes

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(V, INT_MAX);
        pq.push({0, S});
        ans[S] = 0;
        while(!pq.empty()) {
            int node = pq.top().second, d = pq.top().first;
            pq.pop();
            for(auto &it : adj[node]) {
                int adjNode = it[0], dist = it[1];
                int distance = d + dist;
                if(ans[adjNode] > distance) {
                    ans[adjNode] = distance;
                    pq.push({distance, adjNode});
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}