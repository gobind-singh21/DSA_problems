#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9 + 7;
int countWays(vector<int> &arr, int target, int index, vector<vector<int>> &dp) {
    if(index == 0) {
        if(target == 0 && arr[0] == 0)
            return 2;
        if(target == 0 || target == arr[0])
            return 1;
        return 0;
    }
    if(dp[index][target] != -1)
        return dp[index][target];
    int pick = (arr[index] <= target) ? countWays(arr, target - arr[index], index - 1, dp) : 0;
    int nonPick = countWays(arr, target, index - 1, dp);
    return dp[index][target] = (pick + nonPick) % mod;
}

int findWays(vector<int> &arr, int tar) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    countWays(arr, tar, n - 1, dp);
}

int main() {
    return 0;
}