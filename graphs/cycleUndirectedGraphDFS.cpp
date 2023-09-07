#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool checkCycle(int currNode, int parent, vector<int> adj[], bool vis[]) {
        for(int &node : adj[currNode]) {
            bool haveCycle = false;
            if(!vis[node]) {
                vis[node] = true;
                haveCycle = checkCycle(node, currNode, adj, vis);
            }
            else if(node != parent)
                return true;
            if(haveCycle)
                return true;
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V] = {false};
        for(int i = 0; i < V; i++)
            if(!vis[i])
                if(checkCycle(i, -1, adj, vis))
                    return true;
        return false;
    }
};

int main() {
    return 0;
}