#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<vector<int>> adjList, vector<int> color, int Color, int node) {
    int n = adjList[node].size();
    for(int i = 0; i < n; i++) {
        if(color[adjList[node][i]] == Color)
            return false;
    }
    return true;
}

bool colorCombination(vector<vector<int>> adjList, int m, int currNode, vector<int> color) {
    if(currNode == adjList.size())
        return true;
    // int n = adjList[currNode].size();
    for(int i = 0; i < m; i++) {
        if(isPossible(adjList, color, i, currNode)) {
            color[currNode] = i;
            if(colorCombination(adjList, m, currNode + 1, color))
                return true;
            color[currNode] = -1;
        }
    }
    return false;
}

bool coloring(vector<vector<int>> edges, int n, int m) {
    vector<int> color(n, -1);
    vector<vector<int>> adjList(n, vector<int>(0));
    int num = edges.size();
    for(int i = 0; i < num; i++) {
        int node1 = edges[i][0] - 1, node2 = edges[i][1] - 1;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }
    return colorCombination(adjList, m, 0, color);
}

int main() {
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{4,1},{1,3}};
    cout << coloring(edges, 4, 3);
    return 0;
}