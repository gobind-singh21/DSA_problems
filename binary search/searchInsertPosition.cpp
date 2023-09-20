#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	int start = 0, end = n - 1, ans = n;
	while(start <= end) {
		int mid = start + ((end - start) >> 1);
		if(arr[mid] == x)
			return mid;
		else if(arr[mid] > x) {
			ans = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return ans;
}

int searchInsert(vector<int>& arr, int m) {
	return lowerBound(arr, arr.size(), m);
}

int main() {
    return 0;
}