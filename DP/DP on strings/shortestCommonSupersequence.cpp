#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // LCS code
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Modified print LCS
        int length = n + m - dp[n][m], i = n, j = m, index = length - 1;
        string ans(length, '$');
        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                ans[index] = str1[i - 1];
                i--, j--, index--;
            }
            else if(dp[i][j - 1] > dp[i - 1][j]) {
                ans[index] = str2[j - 1];
                index--, j--;
            }
            else {
                ans[index] = str1[i - 1];
                index--, i--;
            }
        }
        while(i > 0) {
            ans[index] = str1[i - 1];
            i--, index--;
        }
        while(j > 0) {
            ans[index] = str2[j - 1];
            j--, index--;
        }
        return ans;
    }
};

int main() {
    return 0;
}