#include <bits/stdc++.h>

using namespace std;

// Method 1
class Solution {
    // int solve(vector<int> &prices, int &n, int index, bool buy, int cap, vector<vector<vector<int>>> &dp) {
    //     if(index == n)
    //         return 0;
    //     if(cap == 0)
    //         return 0;
    //     if(dp[index][buy][cap] != -1)
    //         return dp[index][buy][cap];
    //     int profit;
    //     if(buy) {
    //         int take = solve(prices, n, index + 1, false, cap, dp) - prices[index];
    //         int notTake = solve(prices, n, index + 1, buy, cap, dp);
    //         profit = max(take, notTake);
    //     }
    //     else {
    //         int sell = solve(prices, n, index + 1, true, cap - 1, dp) + prices[index];
    //         int notSell = solve(prices, n, index + 1, buy, cap, dp);
    //         profit = max(sell, notSell);
    //     }
    //     return dp[index][buy][cap] = profit;
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> front(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        int profit;
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap < 3; cap++) {
                    if(buy) {
                        int take = front[0][cap] - prices[i];
                        int notTake = front[buy][cap];
                        profit = max(take, notTake);
                    }
                    else {
                        int sell = front[1][cap - 1] + prices[i];
                        int notSell = front[buy][cap];
                        profit = max(sell, notSell);
                    }
                    curr[buy][cap] = profit;
                }
                front = curr;
            }
        }
        return front[1][2];
        // return solve(prices, n, 0, true, 2, dp);
    }
};

// Method 2
class Solution1 {
    
};
int main() {
    return 0;
}