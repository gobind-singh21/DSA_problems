#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    inline bool isValid(vector<vector<int>> &grid, vector<vector<bool>> &vis, int &r, int &c, int &n, int &m) {
        return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c];
    }

    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, queue<pair<pair<int, int>, int>> &q, int &freshOranges, int n, int m) {
        int time = 0;
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,-1,0,1};
        while(!q.empty()) {
            auto temp = q.front();
            int r = temp.first.first, c = temp.first.second, t = temp.second;
            time = (time > t) ? time : t;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nRow = r + dRow[i], nCol = c + dCol[i];
                if(isValid(grid, visited, nRow, nCol, n, m)) {
                    q.push({{nRow, nCol}, t + 1});
                    visited[nRow][nCol] = true;
                    freshOranges--;
                }
            }
        }
        if(freshOranges == 0)
            return time;
        return -1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        int freshOranges = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
                if(grid[i][j] == 1)
                    freshOranges++;
            }
        }
        int ans = bfs(grid, visited, q, freshOranges, n, m);
        return ans;
    }
};

int main() {
    return 0;
}