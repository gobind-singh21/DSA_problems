#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createUndirectedList(vector<vector<int>> &edges, int &n) {
    vector<vector<int>> adjList(n, vector<int>(0));
    for(vector<int> &edge : edges) {
        int src = edge[0], dest = edge[1];
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    return adjList;
}

vector<vector<int>> createUndirectedMatrix(vector<vector<int>> &edges, int &n) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for(vector<int> &edge : edges) {
        int src = edge[0], dest = edge[1];
        adjMatrix[src][dest] = true;
        adjMatrix[dest][src] = true;
    }
    return adjMatrix;
}

vector<vector<int>> createDirectedList(vector<vector<int>> &edges, int &n) {
    vector<vector<int>> adjList(n, vector<int>(0));
    for(vector<int> &edge : edges) {
        int src = edge[0], dest = edge[1];
        adjList[src].push_back(dest);
    }
    return adjList;
}

vector<vector<int>> createDirectedMatrix(vector<vector<int>> &edges, int &n) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    for(vector<int> &edge : edges) {
        int src = edge[0], dest = edge[1];
        adjMatrix[src][dest] = true;
    }
    return adjMatrix;
}

int main() {
    int n;
    cin >> n;
    int edge;
    cin >> edge;
    vector<vector<int>> edges(0);
    while(edge--) {
        int v, u;
        cin >> v >> u;
        vector<int> currEdge = {v, u};
        edges.push_back(currEdge);
    }
    vector<vector<int>> adjList = createUndirectedList(edges, n);
    vector<vector<int>> adjDirectedList = createDirectedList(edges, n);
    vector<vector<int>> adjMatrix = createUndirectedMatrix(edges, n);
    vector<vector<int>> adjDirectedMatrix = createDirectedMatrix(edges, n);
    return 0;
}