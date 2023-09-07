#include <bits/stdc++.h>

using namespace std;

// why use queue because stops will always increase by 1 hence no need of PQ
// Queue structure :
// {stops, {node, distance}}

// TC : O(E), E -> number of edges

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int totalStops = k + 1;
        vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>(0));
        for(vector<int> &edge : flights) {
            int source = edge[0], dest = edge[1], wt = edge[2];
            adjList[source].push_back({dest, wt});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while(!q.empty()) {
            pair<int, pair<int, int>> it = q.front();
            int node = it.second.first, stops = it.first, d = it.second.second;
            q.pop();
            for(pair<int, int> &adj : adjList[node]) {
                int adjNode = adj.first, wt = adj.second, newStop = stops + 1;
                int distance = wt + d;
                if(distance < dist[adjNode] && newStop <= totalStops) {
                    dist[adjNode] = distance;
                    q.push({newStop, {adjNode, distance}});
                }
            }
        }
        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};

int main() {
    Solution obj;
    vector<vector<int>> flights = {{0,1,100},{0,2,100},{2,3,1},{3,4,600},{1,4,602},{4,5,6},{5,6,6}};
    cout << obj.findCheapestPrice(7, flights, 0, 6, 3);
    return 0;
}