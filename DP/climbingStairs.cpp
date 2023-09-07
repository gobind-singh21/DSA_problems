#include <iostream>
#include <vector>

using namespace std;

int function(int currStair, int n, vector<int> &dp) {
    if(dp[currStair] != -1)
        return dp[currStair];
    if(currStair > n)
        return 0;
    if(currStair == n)
        return dp[currStair] = 1;
    return dp[currStair] = function(currStair + 1, n, dp) + function(currStair + 2, n, dp);
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << function(0, n, dp);
    return 0;
}