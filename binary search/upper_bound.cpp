#include <bits/stdc++.h>

using namespace std;

int upperBound(vector<int> &arr, int x, int n){
	int start = 0, end = n - 1, ans = n;
	while(start <= end) {
		int mid = start + ((end - start) >> 1);
		if(arr[mid] <= x)
			start = mid + 1;
		else {
			ans = mid;
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
    return 0;
}