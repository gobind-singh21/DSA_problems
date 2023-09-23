#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxi = 1, lastIndex = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n, 0);
        for(int i = 1; i < n; i++) {
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> ans(maxi);
        int index = maxi - 1;
        while(lastIndex != hash[lastIndex]) {
            ans[index] = nums[lastIndex];
            lastIndex = hash[lastIndex];
            index--;
        }
        ans[0] = nums[lastIndex];
        return ans;
    }
};

int main() {
    return 0;
}