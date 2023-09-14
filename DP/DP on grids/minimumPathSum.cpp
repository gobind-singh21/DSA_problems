#include <iostream>
#include <vector>

using namespace std;

int calculateSum(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &dp) {
    if(x == 0 && y == 0)
        return grid[x][y];
    if(dp[x][y] != -1)
        return dp[x][y];
    int left = (y > 0) ? grid[x][y] + calculateSum(grid, x, y - 1, dp) : INT_MAX;
    int up = (x > 0) ? grid[x][y] + calculateSum(grid, x - 1, y, dp) : INT_MAX;
    return dp[x][y] = min(left, up);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return calculateSum(grid, n - 1, m - 1, dp);
}

int main() {
    return 0;
}