#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    bool dfsCheck(vector<int> adj[], bool visited[], bool pathVis[], int currNode) {
        visited[currNode] = true;
        pathVis[currNode] = true;
        for(int &node : adj[currNode]) {
            if(!visited[node]) {
                bool haveCycle = dfsCheck(adj, visited, pathVis, node);
                if(haveCycle)
                    return true;
            }
            else if(pathVis[node])
                return true;
        }
        pathVis[currNode] = false;
        return false;
    }
public:
    bool isCyclic(int V, vector<int> adj[]) {
        bool visited[V] = {false};
        bool pathVis[V] = {false};
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bool haveCycle = dfsCheck(adj, visited, pathVis, i);
                if(haveCycle)
                    return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}