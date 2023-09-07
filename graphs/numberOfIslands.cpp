#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
    void isIsland(vector<vector<char>> &grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
            return ;
        grid[x][y] = '0';
        isIsland(grid, x - 1, y);
        isIsland(grid, x + 1, y);
        isIsland(grid, x, y - 1);
        isIsland(grid, x, y + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> mat = grid;
        int answer = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == '1') {
                    isIsland(mat, i, j);
                    answer++;
                }
            }
        }
        return answer;
    }
};
inline bool isLand(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    return !(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 || visited[x][y]);
}
void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int startRow, int startCol) {
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;
    while(!q.empty()) {
        pair<int, int> currNode = q.front();
        q.pop();
        int x = currNode.first, y = currNode.second;
        for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
                int nextRow = x + dx, nextCol = y + dy;
                if(isLand(grid, visited, nextRow, nextCol)) {
                    q.push({nextRow, nextCol});
                    visited[nextRow][nextCol] = true;
                }
            }
        }
    }
}

int numIslands(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size(), answer = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                bfs(grid, visited, i, j);
                answer++;
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}};
    cout << numIslands(grid) << endl;
    return 0;
}