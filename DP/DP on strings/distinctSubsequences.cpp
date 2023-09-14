#include <bits/stdc++.h>

using namespace std;

class Solution {
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if(j == 0)
          return 1;
        if(i == 0)
          return 0;

        if(dp[i][j] != -1)
          return dp[i][j];

        if(s1[i - 1] == s2[j - 1])
          return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp) + solve(s1, s2, i - 1, j, dp);
        return dp[i][j] = solve(s1, s2, i - 1, j, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        // curr[0] = 1;

        for(int i = 1; i <= n; i++) {
          for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1])
              dp[j] = dp[j - 1] + dp[j];
            // else
            //   prev[j] = prev[j];
          }
        //   prev = curr;
        }
        return dp[m];
        // return solve(s, t, n, m, dp);
    }
};

int main() {
    return 0;
}