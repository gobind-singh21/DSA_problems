#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int> &arr, int index, int target, vector<vector<int>> &dp) {
    if(target == 0)
        return true;
    if(index == 0)
        return arr[0] == target;
    if(dp[index][target] != -1)
        return dp[index][target];
    bool pick = false;
    if(target >= arr[index])
        pick = subsetSum(arr, index - 1, target - arr[index], dp);
    if(pick)
        return dp[index][target] = true;
    bool nonPick = subsetSum(arr, index - 1, target, dp);
    return dp[index][target] = nonPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subsetSum(arr, 0, k, dp);
}

int main() {
    return 0;
}