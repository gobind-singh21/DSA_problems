#include <bits/stdc++.h>

using namespace std;

// TC : O(E log E)
// SC : O(E)

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(V, false);
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()) {
            pair<int, int> it = pq.top();
            pq.pop();
            int node = it.second, wt = it.first;
            if(vis[node])
                continue;
            vis[node] = true;
            sum += wt;
            for(vector<int> &a : adj[node]) {
                int adjNode = a[0], w = a[1];
                if(!vis[adjNode]) {
                    pq.push({w, adjNode});
                }
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}