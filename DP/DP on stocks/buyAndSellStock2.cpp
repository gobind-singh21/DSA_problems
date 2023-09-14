#include <bits/stdc++.h>

using namespace std;

class Solution {
    // int solve(vector<int> &prices, int &n, int i, bool buy, vector<vector<int>> &dp) {
    //     if(i == n)
    //         return 0;
    //     int profit = 0;
    //     if(dp[i][buy] != -1)
    //         return dp[i][buy];
    //     if(buy) {
    //         int take = solve(prices, n, i + 1, false, dp) - prices[i];
    //         int notTake = solve(prices, n, i + 1, buy, dp);
    //         profit = max(take, notTake);
    //     }
    //     else {
    //         int sell = solve(prices, n, i + 1, true, dp) + prices[i];
    //         int notSell = solve(prices, n, i + 1, buy, dp);
    //         profit = max(sell, notSell);
    //     }
    //     return dp[i][buy] = profit;
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        int front[2] = {0}, curr[2] = {0};
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy) {
                    int take = front[0] - prices[i];
                    int notTake = front[buy];
                    profit = max(take, notTake);
                }
                else {
                    int sell = front[1] + prices[i];
                    int notSell = front[buy];
                    profit = max(sell, notSell);
                }
                curr[buy] = profit;
            }
            front[0] = curr[0], front[1] = curr[1];
        }
        return front[1];
        // return solve(prices, n, 0, true, dp);
    }
};

int main() {
    return 0;
}