#include <iostream>
#include <vector>

using namespace std;

bool checkSubsetSum(vector<int> &arr, int index, int target, vector<vector<int>> &dp) {
    if(target == 0)
        return true;
    if(index == 0)
        return arr[0] == target;
    if(dp[index][target] != -1)
        return dp[index][target];
    bool pick = false;
    if(target >= arr[index])
        pick = checkSubsetSum(arr, index - 1, target - arr[index], dp);
    if(pick)
        return dp[index][target] = true;
    bool nonPick = checkSubsetSum(arr, index - 1, target, dp);
    return dp[index][target] = nonPick;
}

bool canPartition(vector<int> &arr, int n) {
    long sum = 0;
    for(int i : arr)
        sum += i;
    if(sum % 2)
        return false;
    int target = sum >> 1;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return checkSubsetSum(arr, n - 1, target, dp);
}

int main() {
    return 0;
}