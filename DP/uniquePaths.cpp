#include <bits/stdc++.h>

using namespace std;

int countPaths(int x, int y, vector<vector<int>> &dp) {
    if(dp[x][y] != -1)
        return dp[x][y];
    if(x == 0 || y == 0)
        return 1;
    return dp[x][y] = countPaths(x - 1, y, dp) + countPaths(x, y - 1, dp);
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countPaths(m - 1, n - 1, dp);
}

int main() {
    cout << uniquePaths(20, 20) << endl;
    return 0;
}