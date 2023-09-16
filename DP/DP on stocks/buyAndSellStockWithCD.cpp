#include <bits/stdc++.h>

using namespace std;

class Solution {
    // int solve(vector<int> &prices, int &n, int index, bool buy, vector<vector<int>> &dp) {
    //     if(index >= n)
    //         return 0;
        
    //     if(dp[index][buy] != -1)
    //         return dp[index][buy];

    //     int profit;
    //     if(buy) {
    //         int take = solve(prices, n, index + 1, false, dp) - prices[index];
    //         int notTake = solve(prices, n, index + 1, buy, dp);
    //         profit = max(take, notTake);
    //     }
    //     else {
    //         int sell = solve(prices, n, index + 2, true, dp) + prices[index];
    //         int notSell = solve(prices, n, index + 1, buy, dp);
    //         profit = max(sell, notSell);
    //     }

    //     return dp[index][buy] = profit;
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        vector<int> front1(2, 0), front2(2, 0), curr(2, 0);
        // int profit;
        for(int i = n - 1; i >= 0; i--) {
            curr[1] = max(front1[0] - prices[i], front1[1]);
            curr[0] = max(front2[1] + prices[i], front1[0]);
            front2 = front1;
            front1 = curr;
        }
        return front1[1];
        // return solve(prices, n, 0, true, dp);
    }
};

int main() {
    return 0;
}