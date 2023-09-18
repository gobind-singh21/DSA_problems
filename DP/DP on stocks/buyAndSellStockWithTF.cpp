#include <bits/stdc++.h>

using namespace std;

class Solution {
    // int solve(vector<int> &prices, int &fee, int &n, int index, bool buy, vector<vector<int>> &dp) {
    //     if(index == n)
    //         return 0;
        
    //     if(dp[index][buy] != -1)
    //         return dp[index][buy];

    //     int profit;
    //     if(buy) {
    //         int take = solve(prices, fee, n, index + 1, false, dp) - prices[index] - fee;
    //         int notTake = solve(prices, fee, n, index + 1, buy, dp);
    //         profit = max(take, notTake);
    //     }
    //     else {
    //         int sell = solve(prices, fee, n, index + 1, true, dp) + prices[index];
    //         int notSell = solve(prices, fee, n, index + 1, buy, dp);
    //         profit = max(sell, notSell);
    //     }
    //     return dp[index][buy] = profit;
    // }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        vector<int> front(2, 0), curr(2, 0);
        for(int i = n - 1; i >= 0; i--) {
            curr[1] = max(front[0] - prices[i], front[1]);
            curr[0] = max(front[1] + prices[i] - fee, front[0]);
            front = curr;
        }
        return curr[1];
        // return solve(prices, fee, n, 0, true, dp);
    }
};

int main() {
    return 0;
}