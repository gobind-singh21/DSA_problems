#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        for(int i = 0; i < V; i++) {
            for(int &node : adj[i])
                indegree[node]++;
        }
        queue<int> q;
        for(int i = 0; i < V; i++)
            if(indegree[i] == 0)
                q.push(i);

        vector<int> answer;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            answer.push_back(node);
            for(int &it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return answer;
    }
};

int main() {
    return 0;
}