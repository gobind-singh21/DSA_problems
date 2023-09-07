#include <iostream>
#include <vector>

using namespace std;

long countWays(vector<int> &arr, int target, int index, vector<vector<long>> dp) {
    if(target == 0)
        return 1;
    if(index == 0) {
        return target % arr[0] == 0;
    }
    if(dp[index][target] != -1)
        return dp[index][target];
    long take = 0;
    if(arr[index] <= target)
        take = countWays(arr, target - arr[index], index, dp);
    long notTake = countWays(arr, target, index - 1, dp);
    return dp[index][target] = take + notTake;
}

long countWaysToMakeChange(int *denomination, int n, int value) {
    vector<int> numbers(denomination, denomination + n);
    // vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    vector<long> prev(value + 1, 0), curr(value + 1, 0);
    for(int target = 0; target <= value; target++)
        prev[target] = target % numbers[0] == 0;
    for(int i = 1; i < n; i++) {
        for(int target = 1; target <= value; target++) {
            long take = 0;
            if(numbers[i] <= target)
                take = curr[target - numbers[i]];
            long nonTake = prev[target];
            curr[target] = take + nonTake;
        }
        curr = prev;
    }
    return curr[value];
}

int main() {
    return 0;
}