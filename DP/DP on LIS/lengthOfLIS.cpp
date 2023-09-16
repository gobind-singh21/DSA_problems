#include <bits/stdc++.h>

using namespace std;

// Method 1

class Solution {
    // int solve(vector<int> &nums, int &n, int index, int prev, vector<vector<int>> &dp) {
    //     if(index == n)
    //         return 0;
        
    //     if(dp[index][prev + 1] != -1)
    //         return dp[index][prev];

    //     int take = INT_MIN;
    //     if(prev == -1 || nums[prev] < nums[index])
    //         take = 1 + solve(nums, n, index + 1, index, dp);
    //     int notTake = solve(nums, n, index + 1, prev, dp);
    //     return dp[index][prev + 1] = max(take, notTake);
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> front(n + 1, 0), curr(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            for(int prev = i - 1; prev >= -1; prev--) {
                int len = front[prev + 1];
                if(prev == -1 || nums[i] > nums[prev])
                    len = max(len, 1 + front[i + 1]);
                curr[prev + 1] = len;
            }
            front = curr;
        }
        return curr[0];
        // return solve(nums, n, 0, -1, dp);
    }
};

// Method 2

class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 1; i < n; i++) {
            for(int prev = 0; prev < i; prev++)
                if(nums[prev] < nums[i])
                    dp[i] = max(1 + dp[prev], dp[i]);
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

int main() {
    return 0;
}