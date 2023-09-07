#include <bits/stdc++.h>
#include <climits>

using namespace std;

// int solve(vector<int> &profit, vector<int> &weights, vector<vector<int>> &dp, int index, int weight) {
//     if(index == 0) {
//         return (weight / weights[0]) * profit[0];
//     }

//     if(dp[index][weight] != -1)
//         return dp[index][weight];

//     int take = (weights[index] <= weight) ? profit[index] + solve(profit, weights, dp, index, weight - weights[index]) : INT_MIN;
//     int nonTake = solve(profit, weights, dp, index - 1, weight);

//     return dp[index][weight] = max(take, nonTake);
// }

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt) {
    // vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    vector<int> prev(w + 1, 0), curr(w + 1, 0);

    for(int i = 0; i < n; i++)
        prev[i] = (i / wt[0]) * val[0];
    
    for(int i = 1; i < n; i++) {
        for(int W = 0; W <= w; W++) {
            int take = INT_MIN;
            if(wt[i] <= W)
                take = val[i] + curr[W - wt[i]];
            int nonTake = prev[W];
            curr[W] = max(take, nonTake);
        }
    }

    return prev[w];
}

int main() {
    return 0;
}