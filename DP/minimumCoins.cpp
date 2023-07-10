#include <iostream>
#include <vector>

using namespace std;

int numberOfElements(vector<int> &nums, int index, int target, vector<vector<int>> &dp) {
    if(target == 0)
        return 0;
    if(index == 0) {
        if(target % nums[index] == 0)
            return target / nums[index];
        return 1e5;
    }
    if(dp[index][target] != -1)
        return dp[index][target];
    int nonPick = numberOfElements(nums, index - 1, target, dp);
    int pick = (nums[index] <= target) ? 1 + numberOfElements(nums, index, target - nums[index], dp) : INT_MAX;
    return dp[index][target] = min(pick, nonPick);
}

int minimumElements(vector<int> &nums, int x) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    // for(int i = 0; i < n; i++) {
    //     dp[i][0] = 0;
    // }
    
    int ans = numberOfElements(nums, n - 1, x, dp);
    if(ans >= 1e9)
        return -1;
    return ans;
}

int main() {
    return 0;
}