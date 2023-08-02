#include <bits/stdc++.h>

using namespace std;

// why use queue in this because here every node in queue will always be arranged in increasing order of
// distance so we don't require extra time complexity of log n of priority queue in this

class Solution {
    inline bool isValid(vector<vector<int>> &grid, int &x, int &y, int &n, int &m) {
        return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1;
    }
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> dest) {
        if(source == dest)
            return 0;
        int n = grid.size(), m = grid[0].size();
        int srcX = source.first, srcY = source.second, destX = dest.first, destY = dest.second;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[srcX][srcY] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {srcX, srcY}});
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};
        while(!q.empty()) {
            pair<int, pair<int, int>> it = q.front();
            q.pop();
            int r = it.second.first, c = it.second.second, d = it.first;
            for(int i = 0; i < 4; i++) {
                int nRow = r + dRow[i], nCol = c + dCol[i], distance = d + 1;
                if(nRow == destX && nCol == destY)
                    return distance;
                if(isValid(grid, nRow, nCol, n, m)) {
                    if(distance < dist[nRow][nCol]) {
                        dist[nRow][nCol] = distance;
                        q.push({distance, {nRow, nCol}});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}