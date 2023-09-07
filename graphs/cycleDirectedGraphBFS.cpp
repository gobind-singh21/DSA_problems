#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        for(int i = 0; i < V; i++)
            for(int &node : adj[i])
                indegree[node]++;
        
        queue<int> q;
        for(int i = 0; i < V; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        int counter = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            counter++;
            for(int &it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return counter == V ? false : true;
    }
};

int main() {
    return 0;
}