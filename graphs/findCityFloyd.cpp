#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++)
            adjMat[i][i] = 0;
        for(vector<int> &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adjMat[u][v] = wt;
            adjMat[v][u] = wt;
        }
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    int distance = adjMat[i][via] + adjMat[via][j];
                    if(distance < adjMat[i][j] && distance <= distanceThreshold){
                        adjMat[i][j] = distance;
                    }
                }
            }
        }
        int currMax = INT_MAX, counter = 0, city = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adjMat[i][j] <= distanceThreshold) {
                    counter++;
                }
            }
            if(counter <= currMax) {
                currMax = counter;
                city = i;
            }
            counter = 0;
        }
        return city;
    }
};

int main() {
    return 0;
}