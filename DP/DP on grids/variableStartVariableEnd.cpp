#include <iostream>
#include <vector>

using namespace std;

// int calculatePathSum(vector<vector<int>> matrix, int x, int y, vector<vector<int>> &dp) {
//     if(x == matrix.size() - 1)
//         return matrix[x][y];
//     if(dp[x][y] != -1)
//         return dp[x][y];
//     int diagonalLeft = (y > 0) ? calculatePathSum(matrix, x + 1, y - 1, dp) : 0;
//     int down = calculatePathSum(matrix, x + 1, y, dp);
//     int diagonalRight = (y < matrix[0].size() - 1) ? calculatePathSum(matrix, x + 1, y + 1, dp) : 0;
//     return dp[x][y] = max(diagonalLeft, max(down, diagonalRight));
// }

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> prev(m), curr(m);
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    for(int i = 0; i < m; i++)
        prev[i] = matrix[0][i];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int up = matrix[i][j] + prev[j];
            int diagonalRight = matrix[i][j];
            if(j < m - 1)
                diagonalRight += prev[j + 1];
            else
                diagonalRight += INT_MIN;
            int diagonalLeft = matrix[i][j];
            if(j > 0)
                diagonalLeft += prev[j - 1];
            else
                diagonalLeft += INT_MIN;
            curr[j] = max(up, max(diagonalLeft, diagonalRight));
        }
        prev = curr;
    }
    int maxi = curr[0];
    for(int j = 1; j < m; j++)
        maxi = max(maxi, curr[j]);
    return maxi;
}

int main() {
    return 0;
}