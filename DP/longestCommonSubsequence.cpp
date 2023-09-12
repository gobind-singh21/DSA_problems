#include <bits/stdc++.h>

using namespace std;

class Solution {
    // int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
    //     if(i == 0 || j == 0)
    //         return 0;
        
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    //     if(text1[i - 1] == text2[j - 1])
    //         return 1 + solve(text1, text2, i - 1, j - 1, dp);
        
    //     return max(solve(text1, text2, i - 1, j, dp), solve(text1, text2, i, j - 1, dp));
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
        // return solve(text1, text2, n, m, dp);
    }
};

int main() {
    return 0;
}