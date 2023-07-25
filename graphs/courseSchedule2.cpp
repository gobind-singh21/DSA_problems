#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>(0));
        for(vector<int> &edge: prerequisites) {
            int src = edge[1], dest = edge[0];
            indegree[dest]++;
            adj[src].push_back(dest);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int &adjNode : adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        if(ans.size() != numCourses)
            return {};
        return ans;
    }
};

int main() {
    return 0;
}