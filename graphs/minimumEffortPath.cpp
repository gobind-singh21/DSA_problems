#include <bits/stdc++.h>

using namespace std;

// TC : O(E log V)
// TC : O(m * n * 4 log (m * n))
// SC : O(m * n)

class Solution {
    inline bool isValid(int &r, int &c, int &n, int &m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};
        while(!pq.empty()) {
            pair<int, pair<int, int>> it = pq.top();
            pq.pop();
            int x = it.second.first, y = it.second.second, diff = it.first;
            if(x == n - 1 && y == m - 1)    
                return diff;
            for(int i = 0; i < 4; i++) {
                int nRow = x + dRow[i], nCol = y + dCol[i];
                if(isValid(nRow, nCol, n, m)) {
                    int wt = abs(heights[x][y] - heights[nRow][nCol]);
                    int newEffort = max(wt, diff);
                    if(newEffort < effort[nRow][nCol]) {
                        effort[nRow][nCol] = newEffort;
                        pq.push({newEffort, {nRow, nCol}});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    return 0;
}