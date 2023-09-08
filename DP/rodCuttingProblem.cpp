#include <bits/stdc++.h>

using namespace std;

// int solve(vector<int> &price, int index, int length, vector<vector<int>> &dp) {
// 	if(index == 0)
// 		return length * price[0];
	
// 	if(dp[index][length] != -1)
// 		return dp[index][length];

// 	int rodLength = index + 1;
// 	int take = (rodLength <= length) ? price[index] + solve(price, index, length - rodLength, dp) : INT_MIN;
// 	int nonTake = solve(price, index - 1, length, dp);

// 	return dp[index][length] = max(take, nonTake);
// }

int cutRod(vector<int> &price, int n) {
	// vector<vector<int>> dp(n, vector<int>(n + 1, 0));
	vector<int> prev(n + 1, 0), curr(n + 1, 0);
	for(int i = 0; i <= n; i++)
		prev[i] = i*price[0];
	
	for(int i = 1; i < n; i++) {
		int rodLength = i + 1;
		for(int len = 0; len <= n; len++) {
			int take = INT_MIN;
			if(rodLength <= len)
				take = price[i] + curr[len - rodLength];
			int nonTake = prev[len];
			curr[len] = max(take, nonTake);
		}
		prev = curr;
	}

	return prev[n];
	// return solve(price, n - 1, n, dp);
}

int main() {
    return 0;
}