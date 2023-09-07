#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> adjRev(n, vector<int>(0));
        for(int i = 0; i < n; i++) {
            int m = graph[i].size();
            inDegree[i] += m;
            for(int &node : graph[i]) {
                adjRev[node].push_back(i);
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ans(0);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int &adjNode : adjRev[node]) {
                inDegree[adjNode]--;
                if(inDegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    return 0;
}