#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adjList(K, vector<int>(0));
        int inDegree[K] = {0};
        bool added[K] = {false};
        for(int i = 0; i < N - 1; i++) {
            int n = dict[i].size(), m = dict[i + 1].size();
            int k = min(n, m);
            for(int j = 0; j < k; j++) {
                if(dict[i][j] != dict[i + 1][j]) {
                    int src = dict[i][j] - 'a', dest = dict[i + 1][j] - 'a';
                    inDegree[dest]++;
                    adjList[src].push_back(dest);
                    break;
                }
            }
        }
        queue<int> q;
        for(int i = 0; i < K; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        string answer = "";
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            answer += char(node + 'a');
            added[node] = true;
            for(int &adjNode : adjList[node]) {
                inDegree[adjNode]--;
                if(inDegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        for(int i = 0; i < K; i++) {
            if(added[i] == false)
                answer += char(i + 'a');
        }
        return answer;
    }
};

int main() {
    return 0;
}