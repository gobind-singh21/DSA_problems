#include <iostream>
#include <vector>

using namespace std;

// int solve(int &r, int &c, vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp) {
//     if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
//         return -1e9;
//     if(i == r - 1) {
//         if(j1 == j2)
//             return grid[i][j1];
//         return grid[i][j1] + grid[i][j2];
//     }

//     if(dp[i][j1][j2] != -1)
//         return dp[i][j1][j2];

//     int maxi = 0;
//     for(int j = -1; j <= 1; j++) {
//         for(int k = -1; k <= 1; k++) {
//             int value;
//             if(j1 == j2)
//                 value = grid[i][j1];
//             else
//                 value = grid[i][j1] + grid[i][j2];
//             value += solve(r, c, grid, i + 1, j1 + j, j2 + k, dp);
//             maxi = max(maxi, value);
//         }
//     }

//     return dp[i][j1][j2] = maxi;
// }

inline bool isValid(int &c, int &j1, int &j2) {
    return j1 >= 0 && j1 < c && j2 >= 0 && j2 < c;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    vector<vector<int>> front(c, vector<int>(c, 0)), curr(c, vector<int>(c, 0));

    for(int j1 = 0; j1 < c; j1++) {
        for(int j2 = 0; j2 < c; j2++) {
            if(j1 == j2)
                front[j1][j2] = grid[r - 1][j1];
            else
                front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for(int i = r - 2; i >= 0; i--) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                int maxi = 0;
                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {
                        int nj1 = j1 + dj1, nj2 = j2 + dj2, value;
                        if(j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if(isValid(c, nj1, nj2))
                            value += front[nj1][nj2];
                        else
                            value += -1e9;
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][c - 1];
    // return solve(r, c, grid, 0, 0, c - 1, dp);
}

int main() {
    return 0;
}