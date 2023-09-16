#include <bits/stdc++.h>

using namespace std;

class Solution {
    // int solve(vector<int> &prices, int &n, int &k, int index, int tranNo, vector<vector<int>> &dp) {
    //     if(index == n || tranNo == k)
    //         return 0;
        
    //     if(dp[index][tranNo] != -1)
    //         return dp[index][tranNo];

    //     int profit;
    //     if(tranNo % 2 == 0) {
    //         int buy = solve(prices, n, k, index + 1, tranNo + 1, dp) - prices[index];
    //         int notBuy = solve(prices, n, k, index + 1, tranNo, dp);
    //         profit = max(buy, notBuy);
    //     }
    //     else {
    //         int sell = solve(prices, n, k, index + 1, tranNo + 1, dp) + prices[index];
    //         int notSell = solve(prices, n, k, index + 1, tranNo, dp);
    //         profit = max(sell, notSell);
    //     }
    //     return dp[index][tranNo] = profit;
    // }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), transactions = k << 1;
        // vector<vector<int>> dp(n + 1, vector<int>(transactions + 1, 0));
        vector<int> front(transactions + 1, 0), curr(transactions + 1, 0);
        int profit;
        for(int i = n - 1; i >= 0; i--) {
            for(int tran = transactions - 1; tran >= 0; tran--) {
                if(tran % 2 == 0) {
                    int buy = front[tran + 1] - prices[i];
                    int notBuy = front[tran];
                    profit = max(buy, notBuy);
                }
                else {
                    int sell = front[tran + 1] + prices[i];
                    int notSell = front[tran];
                    profit = max(sell, notSell);
                }
                curr[tran] = profit;
            }
            front = curr;
        }
        return front[0];
    }
};

int main() {
    return 0;
}