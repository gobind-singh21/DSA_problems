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
    // void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int r, int c, int &n, int &m) {
    //     int dRow[] = {-1, 0, 1, 0};
    //     int dCol[] = {0, -1, 0, 1};
    //     for(int i = 0; i < 4; i++) {
    //         int nRow = r + dRow[i], nCol = c + dCol[i];
    //         if(isValid(grid, vis, r, c, n, m)) {
    //             vis[nRow][nCol] = true;
    //             dfs(grid, vis, nRow, nCol, n, m);
    //         }
    //     }
    // }

    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, queue<pair<int, int>> &q, int &n, int &m) {
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};
        while(!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nRow = r + dRow[i], nCol = c + dCol[i];
                if(isValid(grid, vis, nRow, nCol, n, m)) {
                    vis[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int countOnes(vector<vector<int>> &grid, vector<vector<bool>> &vis, int &n, int &m) {
        int answer = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1 && !vis[i][j])
                    answer++;
        return answer;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1 && !vis[i][0]) {
                q.push({i, 0});
                vis[i][0] = true;
                // dfs(grid, vis, i, 0, n, m);
            }
            if(grid[i][m - 1] == 1 && !vis[i][m - 1]) {
                q.push({i, m - 1});
                vis[i][m - 1] = true;
                // dfs(grid, vis, i, m - 1, n, m);
            }
        }

        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 1 && !vis[0][i]) {
                q.push({0, i});
                vis[0][i] = true;
                // dfs(grid, vis, 0, i, n, m);
            }
            if(grid[n - 1][i] == 1 && !vis[n - 1][i]) {
                q.push({n - 1, i});
                vis[n - 1][i] = true;
                // dfs(grid, vis, n - 1, i, n, m);
            }
        }

        bfs(grid, vis, q, n, m);

        // for(int i = 0; i < n; i++) {
        //     if(grid[i][0] == 1 && !vis[i][0]) {
        //         vis[i][0] = true;
        //         dfs(grid, vis, i, 0, n, m);
        //     }
        //     if(grid[i][m - 1] == 1 && !vis[i][m - 1]) {
        //         vis[i][m - 1] = true;
        //         dfs(grid, vis, i, m - 1, n, m);
        //     }
        // }

        // for(int i = 0; i < m; i++) {
        //     if(grid[0][i] == 1 && !vis[0][i]) {
        //         vis[0][i] = true;
        //         dfs(grid, vis, 0, i, n, m);
        //     }
        //     if(grid[n - 1][i] == 1 && !vis[n - 1][i]) {
        //         vis[n - 1][i] = true;
        //         dfs(grid, vis, n - 1, i, n, m);
        //     }
        // }
        
        int ans = countOnes(grid, vis, n, m);
        return ans;
    }
};

int main() {
    return 0;
}