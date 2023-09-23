#include <bits/stdc++.h>

using namespace std;

bool comp(string &s1, string &s2) {
    return s1.size() < s2.size();
}

class Solution {
    bool compare(string &str1, string &str2) {
        int n = str1.size(), m = str2.size();
        if(n != m + 1)
            return false;
        int i = 0, j = 0;
        while(i < n) {
            if(j < m && str1[i] == str2[j])
                j++;
            i++;
        }
        return i == n && j == m;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size(), maxi = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(compare(words[i], words[j]) && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

int main() {
    return 0;
}