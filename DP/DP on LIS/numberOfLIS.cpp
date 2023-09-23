#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 1, ans = 1;
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }
                else if(nums[i] > nums[j] && dp[i] == 1 + dp[j])
                    cnt[i] += cnt[j];
            }
            if(maxi < dp[i]) {
                maxi = dp[i];
                ans = cnt[i];
            }
            else if(maxi == dp[i])
                ans += cnt[i];
        }
        return ans;
    }
};

int main() {
    return 0;
}