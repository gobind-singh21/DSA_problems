#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool dfsCheck(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &pathVisited, int currNode) {
        visited[currNode] = true;
        pathVisited[currNode] = true;

        for(int &node : graph[currNode]) {
            if(!visited[node]) {
                bool haveCycle = dfsCheck(graph, visited, pathVisited, node);
                if(haveCycle)
                    return true;
            }
            else if(pathVisited[node])
                return true;
        }
        pathVisited[currNode] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> pathVisited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                dfsCheck(graph, visited, pathVisited, i);
        }
        vector<int> safeNode(0);
        for(int i = 0; i < n; i++) {
            bool isSafeNode = visited[i] && !pathVisited[i];
            if(isSafeNode)
                safeNode.push_back(i);
        }
        return safeNode;
    }
};

int main() {
    return 0;
}