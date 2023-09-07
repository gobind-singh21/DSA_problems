#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int calculateMax(vector<int> &value, vector<int> &wt, int index, int weight, vector<vector<int>> &dp) {
    if(index == 0) {
        if(weight >= wt[0])
            return value[index];
        return 0;
    }
    if(dp[index][weight] != -1)
        return dp[index][weight];
    int notTake = calculateMax(value, wt, index - 1, weight, dp);
    int take = INT_MIN;
    if(wt[index] <= weight)
        take = value[index] + calculateMax(value, wt, index - 1, weight - wt[index], dp);
    return dp[index][weight] = max(notTake, take);
}

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
    for(int i = weight[0]; i <= maxWeight; i++)
        prev[i] = value[0];
    for(int i = 1; i < n; i++) {
        for(int wt = 0; wt <= maxWeight; wt++) {
            int notTake = prev[wt];
            int take = (weight[i] <= wt) ? value[i] + prev[wt - weight[i]] : INT_MIN;
            curr[wt] = max(take, notTake);
        }
        prev = curr;
    }
    return curr[maxWeight];
}

int main() {
    return 0;
}