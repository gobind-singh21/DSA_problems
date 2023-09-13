#include <bits/stdc++.h>

using namespace std;

class Solution {
    // int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp) {
    //     if(i == 0)
    //         return j;
    //     if(j == 0)
    //         return i;
        
    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     if(word1[i - 1] == word2[j - 1])
    //         return dp[i][j] = solve(word1, word2, i - 1, j - 1, dp);
        
    //     int insert = 1 + solve(word1, word2, i, j - 1, dp);
    //     int deletion = 1 + solve(word1, word2, i - 1, j, dp);
    //     int replace = 1 + solve(word1, word2, i - 1, j - 1, dp);

    //     return dp[i][j] = min(replace, min(insert, deletion));
    // }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for(int j = 1; j <= m; j++)
            prev[j] = j;
        // for(int j = 1; j <= m; j++)
        //     dp[0][j] = j;
        // for(int i = 1; i <= n; i++)
        //     dp[i][0] = i;
        
        for(int i = 1; i <= n; i++) {
            curr[0] = i;
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(prev[j], min(prev[j - 1], curr[j - 1]));
            }
            prev = curr;
        }
        return prev[m];
        // return solve(word1, word2, n - 1, m - 1, dp);
    }
};

int main() {
    return 0;
}