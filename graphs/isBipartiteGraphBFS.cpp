#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    bool isPossible(vector<vector<int>> &graph, vector<int> &color, int nodeColor, int &node) {
        int m = graph[node].size();
        for(int i = 0; i < m; i++) {
            int adjNode = graph[node][i];
            if(color[adjNode] == nodeColor)
                return false;
        }
        return true;
    }
    bool bfs(vector<vector<int>> &graph, vector<int> &color, int node, vector<bool> &visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()) {
            int currNode = q.front();
            bool color0 = isPossible(graph, color, 0, currNode);
            bool color1 = isPossible(graph, color, 1, currNode);
            if(!color0 && !color1)
                return false;
            int nodeColor = (color0) ? 0 : 1;
            color[currNode] = nodeColor;
            q.pop();
            for(int &adjNode : graph[currNode]) {
                if(!visited[adjNode]) {
                    q.push(adjNode);
                    visited[adjNode] = true;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            bool isBipartite = true;
            if(!visited[i])
                isBipartite = bfs(graph, color, i, visited);
            if(!isBipartite)
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}