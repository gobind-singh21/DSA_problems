#include <iostream>
#include <vector>

using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n) {
    int sum = 0;
    for(int i : arr)
        sum += i;
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
    for(int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int i = 1; i < n; i++) {
        for(int target = 1; target <= sum; target++) {
            bool nonPick = dp[i - 1][target];
            bool pick = (arr[i] <= target) ? dp[i - 1][target - arr[i]] : false;
            dp[i][target] = nonPick or pick;
        }
    }

    int ans = sum;
    for(int i = 0; i <= sum >> 1; i++) {
        if(dp[n - 1][i])
            ans = min(ans, abs(sum - (i << 1)));
    }
    return ans;
}

int main() {
    return 0;
}