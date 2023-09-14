#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxProfit = 0, mini = prices[0], n = prices.size();
        for(int i = 1; i < n; i++) {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};

int main() {
    return 0;
}