#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9 + 7;
int calculatePaths(int x, int y, vector<vector<int>> &mat, vector<vector<int>> &dp) {
    if(mat[x][y] == -1)
        return 0;
    if(x == 0 && y == 0)
        return 1;
    if(dp[x][y] != -1)
        return dp[x][y];
    int left = (y > 0) ? calculatePaths(x, y - 1, mat, dp) : 0;
    int up = (x > 0) ? calculatePaths(x - 1, y, mat, dp) : 0;
    return dp[x][y] = (left + up) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return calculatePaths(n - 1, m - 1, mat, dp);
}

int main() {
    return 0;
}