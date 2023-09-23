#include <bits/stdc++.h>

using namespace std;

int longestBitonicSubsequence(vector<int>& arr, int n) {
	vector<int> dp1(n, 1), dp2(n, 1);
	int maxi = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[i] > arr[j] && dp1[i] < 1 + dp1[j])
				dp1[i] = 1 + dp1[j];
			if(arr[n - i - 1] > arr[n - j - 1] && dp2[n - i - 1] < 1 + dp2[n - j - 1])
				dp2[n - i - 1] = 1 + dp2[n - j - 1];
		}
	}
	for(int i = 0; i < n; i++) {
		int len = dp1[i] + dp2[i] - 1;
		maxi = max(maxi, len);
	}
	return maxi;
}

int main() {
    return 0;
}