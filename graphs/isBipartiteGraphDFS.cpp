#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool isPossible(vector<vector<int>> &graph, vector<int> &color, int nodeColor, int currNode) {
        for(int &node : graph[currNode]) {
            int adjColor = color[node];
            if(adjColor == nodeColor)
                return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>> &graph, vector<int> &color, vector<bool> &visited, int currNode) {
        bool color0 = isPossible(graph, color, 0, currNode);
        bool color1 = isPossible(graph, color, 1, currNode);
        if(!color0 && !color1)
            return false;
        int nodeColor = color0 ? 0 : 1;
        color[currNode] = nodeColor;
        for(int &node : graph[currNode]) {
            if(!visited[node]) {
                visited[node] = true;
                bool isBipartite = dfs(graph, color, visited, node);
                if(!isBipartite)
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                bool bipartite = dfs(graph, color, visited, i);
                if(!bipartite)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}