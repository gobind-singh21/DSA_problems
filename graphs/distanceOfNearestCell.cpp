#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    inline bool isValid(vector<vector<bool>> &vis, int &r, int &c, int &n, int &m) {
        return r >= 0 && r < n && c >= 0 && c < m && !vis[r][c];
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }
        while(!q.empty()) {
            int r = q.front().first.first, c = q.front().first.second, d = q.front().second;
            q.pop();
            if(mat[r][c] == 0)
                ans[r][c] = 0;
            else
                ans[r][c] = d;
            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, -1, 0, 1};
            for(int i = 0 ; i < 4; i++) {
                int nRow = r + dRow[i], nCol = c + dCol[i];
                if(isValid(visited, nRow, nCol, n, m)) {
                    q.push({{nRow, nCol}, d + 1});
                    visited[nRow][nCol] = true;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}