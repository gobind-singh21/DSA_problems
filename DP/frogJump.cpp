#include <iostream>
#include <vector>

using namespace std;

int function(vector<int> &height, vector<int> &dp, int n, int currStair) {
    if(dp[currStair] != -1)
        return dp[currStair];
    if(currStair == 0)
        return 0;
    int num1 = function(height, dp, n, currStair - 1) + abs(height[currStair] - height[currStair - 1]);
    int num2;
    if(currStair > 1)
        num2 = function(height, dp, n, currStair - 2) + abs(height[currStair] - height[currStair - 2]);
    return dp[currStair] = num1 < num2 ? num1 : num2;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << function() << endl;
    return 0;
}