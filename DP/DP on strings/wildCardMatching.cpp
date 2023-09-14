#include <bits/stdc++.h>

using namespace std;

class Solution {
    // bool solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    //     if(j == 0 && i == 0)
    //         return true;
    //     if(i == 0)
    //         return false;
    //     if(j == 0) {
    //         for(int index = 0; index < i; index++)
    //             if(s1[index] != '*')
    //                 return false;
    //         return true;
    //     }
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     if(s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
    //         return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp);
    //     else if(s1[i - 1] == '*') {
    //         return solve(s1, s2, i - 1, j, dp) || solve(s1, s2, i, j - 1, dp);
    //     }
    //     return dp[i][j] = false;
    // }
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        // for(int i = 1; i <= n; i++) {
        //     bool flag = true;
        //     for(int index = 0; index < i; index++) {
        //         if(p[index] != '*') {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     dp[i][0] = flag;
        // }

        for(int i = 1; i <= n; i++) {
            bool flag = true;
            for(int index = 0; index < i; index++) {
                if(p[index] != '*') {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for(int j = 1; j <= m; j++) {
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    curr[j] = prev[j - 1];
                else if(p[i - 1] == '*')
                    curr[j] = prev[j] || curr[j - 1];
                else
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
        // return solve(p, s, n, m, dp);
    }
};

int main() {
    return 0;
}