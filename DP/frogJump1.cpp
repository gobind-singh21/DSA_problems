#include <iostream>
#include <vector>

using namespace std;

int function(vector<int> &height, vector<int> &dp, int currStair, int n, int k) {
    if(dp[currStair] != -1)
        return dp[currStair];
    if(currStair == 0)
        return 0;
    int ans = INT_MAX;
    for(int i = 1; i <= k; i++) {
        if(currStair - i >= 0) {
            int num = function(height, dp, currStair - i, n, k);
            ans = ans > num ? num : ans;
        }
    }
    return dp[currStair] = ans;
}

int main() {
    return 0;
}