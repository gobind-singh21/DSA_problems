#include <iostream>
#include <vector>

using namespace std;

int function(vector<int> &nums, int index, vector<int> &dp) {
    if(index == 0)
        return nums[0];
    if(index < 0)
        return 0;
    if(dp[index] != -1)
        return dp[index];
    int num1 = nums[index] + function(nums, index - 2, dp);
    int num2 = nums[index] + function(nums, index - 1, dp);

    return dp[index] = num1 > num2 ? num1 : num2;
}

int tabulation(vector<int> &nums) {
    int prev2 = 0, prev = nums[0], n = nums.size(), curri;
    for(int i = 1; i < n; i++) {
        int take = nums[i];
        if(i > 1)
            take += prev2;
        int nonTake = prev;
        curri = take > nonTake ? take : nonTake;
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

int main() {
    vector<int> nums = {2,1,4,9};
    vector<int> dp(nums.size(), -1);
    cout << function(nums, nums.size() - 1, dp);
    return 0;
}