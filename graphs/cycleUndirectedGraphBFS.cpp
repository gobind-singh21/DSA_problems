#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
    bool checkCycle(int node, vector<int> adj[], bool vis[]) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node] = true;
        while(!q.empty()) {
            int currNode = q.front().first, parent = q.front().second;
            q.pop();
            for(int &node : adj[currNode]) {
                if(!vis[node]) {
                    vis[node] = true;
                    q.push({node, currNode});
                }
                else if(parent != node)
                    return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V] = {0};
        for(int i = 0; i < V; i++)
            if(!vis[i])
                if(checkCycle(i, adj, vis))
                    return true;
        return false;
    }
};

int main() {
    return 0;
}