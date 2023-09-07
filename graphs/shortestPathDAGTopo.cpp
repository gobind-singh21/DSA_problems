#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

class Solution {
    stack<int> st;
    void dfsHelper(vector<vector<pair<int, int>>> &adj, bool visited[], int currNode) {
        for(pair<int, int> &it : adj[currNode]) {
            int node = it.first;
            if(!visited[node]) {
                visited[node] = true;
                dfsHelper(adj, visited, node);
            }
        }
        st.push(currNode);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adjList(N, vector<pair<int, int>>(0));
        for(vector<int> &edge : edges) {
            int src = edge[0], dest = edge[1], wt = edge[2];
            adjList[src].push_back({dest, wt});
        }
        bool visited[N] = {false};
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                visited[i] = true;
                dfsHelper(adjList, visited, i);
            }
        }
        vector<int> dist(N, 1e8);
        dist[0] = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            for(pair<int, int> &adjNode : adjList[node]) {
                int v = adjNode.first;
                int wt = adjNode.second;
                if(dist[node] + wt < dist[v])
                    dist[v] = dist[node] + wt;
            }
        }
        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e8)
                dist[i] = -1;
        }
        return dist;
    }
};

int main() {
    return 0;
}