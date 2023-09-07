#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

class Solution {
    inline bool isValid(vector<vector<int>> &grid, vector<vector<bool>> &vis, int &r, int &c, int &n, int &m) {
        return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c];
    }
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int r, int c, int &r0, int &c0, int &n, int &m, vector<pair<int, int>> &vec) {
        vis[r][c] = true;
        vec.push_back({r - r0,c - c0});
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};
        for(int i = 0; i < 4; i++) {
            int nRow = r + dRow[i], nCol = c + dCol[i];
            if(isValid(grid, vis, nRow, nCol, n, m)) {
                dfs(grid, vis, nRow, nCol, r0, c0, n, m, vec);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    vector<pair<int, int>> vec(0);
                    dfs(grid, vis, i, j, i, j, n, m, vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main() {
    return 0;
}