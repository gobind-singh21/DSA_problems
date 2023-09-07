#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    stack<int> nodes;
    void dfs(vector<int> adj[], bool visited[], int currNode) {
        visited[currNode] = true;
        for(int &node : adj[currNode]) {
            if(!visited[node])
                dfs(adj, visited, node);
        }
        nodes.push(currNode);
    }
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        bool visited[V] = {false};
        for(int i = 0; i < V; i++) {
            if(!visited[i])
                dfs(adj, visited, i);
        }
        vector<int> answer(0);
        while(!nodes.empty()) {
            int node = nodes.top();
            nodes.pop();
            answer.push_back(node);
        }
        return answer;
	}
};

int main() {
    return 0;
}